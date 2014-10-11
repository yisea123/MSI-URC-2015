#define _DEBUG_
#define _SIMULATION_DATA_

#include <odometry.hpp>

#ifdef _DEBUG_
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
std::ofstream ya_f, pi_f, ro_f;
std::ofstream px_f, py_f, pz_f;
std::ofstream vx_f, vy_f, vz_f;
#ifdef _SIMULATION_DATA_
std::ifstream ps_i, th_i, ph_i;
std::ifstream p_i, q_i, r_i;
std::ifstream ax_i, ay_i, az_i;
std::ifstream magx_i, magy_i, magz_i;
std::ifstream Vd_i, Ve_i, Vn_i;
#endif
#endif

matrix<double> P (6,6);
matrix<double> Q (6,6);
matrix<double> R (3,3);
matrix<double> temper (3,3);
matrix<double> innov(2000,3);
int i=0;
matrix<double> H (3,6);

void Load() {
  ahrs(0) = 0;
  ahrs(1) = 0;
  ahrs(2) = 0;
  ahrs(3) = 0.01;
  ahrs(4) = 0.01;
  ahrs(5) = 0.01;

  acc(0) = 0;
  acc(1) = 0;
  acc(2) = -1*GG;

vel(0) = 0;
vel(1) = 0;
vel(2) = 0;
gps_vel(0) = 0;
gps_vel(1) = 0;
gps_vel(2) = 0;
//  fill(vel,0);
//  fill(gps_vel,0);
//  fill(P,0);

for (int i = 0; i < P.size1(); i++) {
          for (int j = 0; j < P.size2(); j++) {
            P(i,j) = 0;
          }
        }
  P(0,0) = 25;
  P(1,1) = 25;
  P(2,2) = 25;
  P(3,3) = 0.25;
  P(4,4) = 0.25;
  P(5,5) = 0.25;


  Q(0,0) =  0.2713;
  Q(0,1) = -0.0462;
  Q(0,2) = -0.1241;
  Q(0,3) = -0.0058;
  Q(0,4) = -0.0040;
  Q(0,5) =  0.0174;
  Q(1,0) = -0.0462;
  Q(1,1) =  0.0080;
  Q(1,2) =  0.0213;
  Q(1,3) =  0.0010;
  Q(1,4) =  0.0007;
  Q(1,5) = -0.0030;
  Q(2,0) = -0.1241;
  Q(2,1) =  0.0213;
  Q(2,2) =  0.0702;
  Q(2,3) =  0.0033;
  Q(2,4) =  0.0018;
  Q(2,5) = -0.0079;
  Q(3,0) = -0.0058;
  Q(3,1) =  0.0010;
  Q(3,2) =  0.0033;
  Q(3,3) =  0.0002;
  Q(3,4) =  0.0001;
  Q(3,5) = -0.0004;
  Q(4,0) = -0.0040;
  Q(4,1) =  0.0007;
  Q(4,2) =  0.0018;
  Q(4,3) =  0.0001;
  Q(4,4) =  0.0001;
  Q(4,5) = -0.0003;
  Q(5,0) =  0.0174;
  Q(5,1) = -0.0030;
  Q(5,2) = -0.0079;
  Q(5,3) = -0.0004;
  Q(5,4) = -0.0003;
  Q(5,5) =  0.0011;

  R(0,0) =  3.4127;
  R(0,1) =  0.1994;
  R(0,2) = -0.4837;
  R(1,0) =  0.1994;
  R(1,1) =  0.2745;
  R(1,2) = -0.0414;
  R(2,0) = -0.4837;
  R(2,1) = -0.0414;
  R(2,2) =  0.4029;

  H(0,0) = 1;
  H(0,1) = 0;
  H(0,2) = 0;
  H(0,3) = 0;
  H(0,4) = 0;
  H(0,5) = 0;
  H(1,0) = 0;
  H(1,1) = 1;
  H(1,2) = 0;
  H(1,3) = 0;
  H(1,4) = 0;
  H(1,5) = 0;
  H(2,0) = 0;
  H(2,1) = 0;
  H(2,2) = 1;
  H(2,3) = 0;
  H(2,4) = 0;
  H(2,5) = 0;

  del_t = 0.02;

std::string SIM_PATH(PACKAGE_PATH);
SIM_PATH = SIM_PATH + "simulation/odometry/";
#ifdef _DEBUG_
  ya_f.open((SIM_PATH + "results/yaw").c_str());
  pi_f.open((SIM_PATH + "results/pitch").c_str());
  ro_f.open((SIM_PATH + "results/roll").c_str());
//  px_f.open((SIM_PATH + "results/px").c_str());
//  py_f.open((SIM_PATH + "results/py").c_str());
//  pz_f.open((SIM_PATH + "results/pz").c_str());
//  vx_f.open((SIM_PATH + "results/vx").c_str());
//  vy_f.open((SIM_PATH + "results/vy").c_str());
//  vz_f.open((SIM_PATH + "results/vz").c_str());
#ifdef _SIMULATION_DATA_
  ps_i.open((SIM_PATH + "data/psi").c_str());
  th_i.open((SIM_PATH + "data/theta").c_str());
  ph_i.open((SIM_PATH + "data/phi").c_str());
  p_i.open((SIM_PATH + "data/p").c_str());
  q_i.open((SIM_PATH + "data/q").c_str());
  r_i.open((SIM_PATH + "data/r").c_str());
  ax_i.open((SIM_PATH + "data/ax").c_str());
  ay_i.open((SIM_PATH + "data/ay").c_str());
  az_i.open((SIM_PATH + "data/az").c_str());
  magx_i.open((SIM_PATH + "data/magx").c_str());
  magy_i.open((SIM_PATH + "data/magy").c_str());
  magz_i.open((SIM_PATH + "data/magz").c_str());
  Vd_i.open((SIM_PATH + "data/Vd").c_str());
  Ve_i.open((SIM_PATH + "data/Ve").c_str());
  Vn_i.open((SIM_PATH + "data/Vn").c_str());
#endif
#endif
}

void constrain(double& in, double period) {
  if (in>0) {
    int temp = (in + period)/(2*period);
    in = in - (float)(temp)*2*period;
  }
  else
  {
    int temp = (in - period)/(2*period);
    in = in - (float)(temp)*2*period;
  }
}

void Loop() {
vector<double> ahrs_act(3);
#ifdef _DEBUG_
#ifdef _SIMULATION_DATA_
if (!( p_i.eof() || q_i.eof() || r_i.eof() || ax_i.eof() || ay_i.eof() || az_i.eof() || magx_i.eof() || magy_i.eof() || magz_i.eof() || Vn_i.eof() || Ve_i.eof() || Vd_i.eof() )) {
  p_i >> p;
  q_i >> q;
  r_i >> r;
  ax_i >> acc(0);
  ay_i >> acc(1);
  az_i >> acc(2);
  magx_i >> Mx;
  magy_i >> My;
  magz_i >> Mz;
  Vn_i >> gps_vel(0);
  Ve_i >> gps_vel(1);
  Vd_i >> gps_vel(2);
  ps_i >> ahrs_act(0);
  th_i >> ahrs_act(1);
  ph_i >> ahrs_act(2);
}
else Shutdown();
//if ( gps_vel(0) == 0 ) return;
#endif
#endif

//-----------------------//
//---- Process Model ----//
//-----------------------//

//-- State Prediction ---//            //uses ahrs, p, q, r, dt
                                       //updates ahrs_dot, ahrs_
  vector<double> ahrs_dot (6);
  vector<double> ahrs_ (6);

  ahrs_dot(0) = (q + ahrs(4))*sin(ahrs(2))/cos(ahrs(1)) + (r + ahrs(5))*cos(ahrs(2))/cos(ahrs(1));
  ahrs_dot(1) = (q + ahrs(4))*cos(ahrs(2))              - (r + ahrs(5))*sin(ahrs(2));
  ahrs_dot(2) = (q + ahrs(4))*sin(ahrs(2))*tan(ahrs(1)) - (r + ahrs(5))*cos(ahrs(2))*tan(ahrs(1)) + (p + ahrs(3));
  ahrs_dot(3) = 0;
  ahrs_dot(4) = 0;
  ahrs_dot(5) = 0;
  ahrs_       = ahrs + ahrs_dot * del_t;
//  constrain(ahrs_(0),PI);
  constrain(ahrs_(1),PI);
  constrain(ahrs_(2),PI);
//  std::cout << "ahrs_d\t" << ahrs_dot << std::endl << std::endl;
//  std::cout << "ahrs_\t" << ahrs_ << std::endl << std::endl;

//--- Velocity Update ---//            //uses ahrs_, gps_vel, vel, dt
                                       //updates vel, v_dot, Rot
  matrix<double> Rot (3,3);
  vector<double> v_dot;
  vector<double> prev_v;

  Rot(0,0) = cos(ahrs_(0))*cos(ahrs_(1));
  Rot(0,1) = sin(ahrs_(0))*cos(ahrs_(1));
  Rot(0,2) = -sin(ahrs_(1));
  Rot(1,0) = sin(ahrs_(2))*sin(ahrs_(1))*cos(ahrs_(0)) - cos(ahrs_(2))*sin(ahrs_(0));
  Rot(1,1) = sin(ahrs_(2))*sin(ahrs_(1))*sin(ahrs_(0)) + cos(ahrs_(2))*cos(ahrs_(0));
  Rot(1,2) = sin(ahrs_(2))*cos(ahrs_(1));
  Rot(2,0) = cos(ahrs_(2))*sin(ahrs_(1))*cos(ahrs_(0)) + sin(ahrs_(2))*sin(ahrs_(0));
  Rot(2,1) = cos(ahrs_(2))*sin(ahrs_(1))*sin(ahrs_(0)) - sin(ahrs_(2))*cos(ahrs_(0));
  Rot(2,2) = cos(ahrs_(2))*cos(ahrs_(1));

  prev_v = vel;
  vel    = prod(Rot, gps_vel);
  v_dot  = (vel - prev_v)/del_t;
//  std::cout << "GPS_Vel\t" << gps_vel << std::endl << std::endl;
//  std::cout << "Rot_Vel\t" << vel << std::endl << std::endl;
//  std::cout << "Vel_dot\t" << v_dot << std::endl << std::endl;

//-----------------------//
//-- Measurement Model --//
//-----------------------//
  vector<double> ahrs_m (3);

//----- Measure Yaw -----//            //uses Mx, My, Mz, ahrs
                                       //updates Mx_h, My_h, ahrs_m(0)
  double My_h, Mx_h;

  Mx_h      = Mx*cos(ahrs(1)) + My*sin(ahrs(2))*sin(ahrs(1)) + Mz*cos(ahrs(2))*sin(ahrs(1));
  My_h      = My*cos(ahrs(2)) + Mz*sin(ahrs(2));
  ahrs_m(0) = atan(My_h/Mx_h);
if(Mx_h<0)
  ahrs_m(0) = PI - ahrs_m(0);
else if((Mx_h>0)&&(My_h>0))
  ahrs_m(0) = 2.0*PI- ahrs_m(0);
else if((Mx_h>0)&&(My_h<0))
  ahrs_m(0) = -ahrs_m(0);
else if((Mx_h==0)&&(My_h<0))
  ahrs_m(0) = PI/2;
else if((Mx_h==0)&&(My_h>0))
  ahrs_m(0) = 3*PI/2;
else ahrs_m(0) = 0;
//  constrain(ahrs_m(0),PI/2.0);

//---- Measure Pitch ----//            //uses acc, vel, v_dot, p, q, r, ahrs_, g
                                       //updates ahrs_m(1)
  ahrs_m(1) = ( acc(0) - v_dot(0) + (r + ahrs_(5))*vel(1) - (q + ahrs_(4))*vel(2) ) / GG;
  if      (ahrs_m(1) >  1) ahrs_m(1) =  PI/2.0;
  else if (ahrs_m(1) < -1) ahrs_m(1) = -PI/2.0;
  else                     ahrs_m(1) =  asin(ahrs_m(1));

//---- Measure Roll -----//            //uses acc, vel, v_dot, p, q, r, ahrs_
                                       //updates ahrs_m(2)
  if ( acc(2) - v_dot(2) + (q + ahrs_(4))*vel(0) - (p + ahrs_(3))*vel(1) == 0 ) {
  if ( acc(1) - v_dot(1) + (p + ahrs_(3))*vel(2) - (r + ahrs_(5))*vel(0) > 0 )      ahrs_m(2) = PI/2.0;
  else if ( acc(1) - v_dot(1) + (p + ahrs_(3))*vel(2) - (r + ahrs_(5))*vel(0) < 0 ) ahrs_m(2) = -PI/2.0;
  else return;
  }
  else {
    ahrs_m(2) = atan2( ( acc(1) - v_dot(1) + (p + ahrs_(3))*vel(2) - (r + ahrs_(5))*vel(0) ),
                       ( acc(2) - v_dot(2) + (q + ahrs_(4))*vel(0) - (p + ahrs_(3))*vel(1) ) );
  }
//  constrain(ahrs_m(2),PI/2.0);

//  std::cout << "Meas_Acc\t" << acc << std::endl << std::endl;
//  std::cout << "Meas_AHRS" << ahrs_m << std::endl << std::endl;
//-- Update Covariance --//            //uses ahrs, p, q, r, P, Q
                                       //updates T, F, P_
  matrix<double> T  (6,6);
  matrix<double> F  (6,6);
  matrix<double> P_ (6,6);

  T(0,0) = 0;
  T(0,1) = sin(ahrs(2))/cos(ahrs(1));
  T(0,2) = cos(ahrs(2))/cos(ahrs(1));
  T(0,3) = 0;
  T(0,4) = 0;
  T(0,5) = 0;
  T(1,0) = 0;
  T(1,1) = cos(ahrs(2));
  T(1,2) = -sin(ahrs(2));
  T(1,3) = 0;
  T(1,4) = 0;
  T(1,5) = 0;
  T(2,0) = 1;
  T(2,1) = sin(ahrs(2))*tan(ahrs(1));
  T(2,2) = cos(ahrs(2))*tan(ahrs(1));
  T(2,3) = 0;
  T(2,4) = 0;
  T(2,5) = 0;
  T(3,0) = 0;
  T(3,1) = 0;
  T(3,2) = 0;
  T(3,3) = 1;
  T(3,4) = 0;
  T(3,5) = 0;
  T(4,0) = 0;
  T(4,1) = 0;
  T(4,2) = 0;
  T(4,3) = 0;
  T(4,4) = 1;
  T(4,5) = 0;
  T(5,0) = 0;
  T(5,1) = 0;
  T(5,2) = 0;
  T(5,3) = 0;
  T(5,4) = 0;
  T(5,5) = 1;
//std::cout<<T;
  F(0,0) = 0;
  F(0,1) = tan(ahrs(1))*( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) )/cos(ahrs(1));
  F(0,2) = ( (q + ahrs(4))*cos(ahrs(2)) - (r + ahrs(5))*sin(ahrs(2)) )/cos(ahrs(1));
  F(0,3) = 0;
  F(0,4) = sin(ahrs(2))/cos(ahrs(1));
  F(0,5) = cos(ahrs(2))/cos(ahrs(1));
  F(1,0) = 0;
  F(1,1) = 0;
  F(1,2) = -( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) );
  F(1,3) = 0;
  F(1,4) = cos(ahrs(2));
  F(1,5) = -sin(ahrs(2));
  F(2,0) = 0;
  F(2,1) = ( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) )/(cos(ahrs(1))*cos(ahrs(1)));
  F(2,2) = tan(ahrs(1))*( (q + ahrs(4))*cos(ahrs(2)) -  (r + ahrs(5))*sin(ahrs(2)) );
  F(2,3) = 1;
  F(2,4) = sin(ahrs(2))*tan(ahrs(1));
  F(2,5) = cos(ahrs(2))*tan(ahrs(1));
  F(3,0) = 0;
  F(3,1) = 0;
  F(3,2) = 0;
  F(3,3) = 0;
  F(3,4) = 0;
  F(3,5) = 0;
  F(4,0) = 0;
  F(4,1) = 0;
  F(4,2) = 0;
  F(4,3) = 0;
  F(4,4) = 0;
  F(4,5) = 0;
  F(5,0) = 0;
  F(5,1) = 0;
  F(5,2) = 0;
  F(5,3) = 0;
  F(5,4) = 0;
  F(5,5) = 0;
//  std::cout<<" T\t"<<T<<std::endl<<std::endl;
//  std::cout<<" F\t"<<F<<std::endl<<std::endl;

  matrix<double> tempa (6,6);
  matrix<double> tempb (6,6);
//  std::cout<<"Q\t"<<Q<<std::endl<<std::endl;
  axpy_prod(Q, trans(T), tempa, true);
//  std::cout<<"QT\t"<<tempa<<std::endl<<std::endl;
  axpy_prod(T, tempa, P_,    true);
//  std::cout<<"TQT\t"<<P_<<std::endl<<std::endl;
  axpy_prod(F, P,     tempb, true);
//  std::cout<<"FP+\t"<<tempb + trans(tempb)<<std::endl<<std::endl;
  P_   = P + ( tempb + trans(tempb) + P_ )*del_t;
//  std::cout<<"P_\t"<<P_<<std::endl<<std::endl;
//----- Correction ------//            //uses P_, ahrs, ahrs_, ahrs_m, H, R
                                       //updates ahrs, P, K
  matrix<double> K      (6,3);
  matrix<double> tempc  (6,3);
  matrix<double> tempd  (3,3);
  matrix<double> tempe  (3,3);
  vector<double> tempv3 (3);
  vector<double> tempv6 (6);

  axpy_prod(P_, trans(H), tempc, true);
  axpy_prod( H, tempc, tempd, true);
  tempd = tempd + R;
  inv(tempd, tempe);
  axpy_prod(tempc, tempe, K, true);
//  std::cout << K << std::endl << std::endl;

  tempv3 = ahrs_m - prod(H, ahrs_);
  ahrs   = ahrs_ + prod(K, tempv3);
//  constrain(ahrs(0),PI);
//  constrain(ahrs(1),PI);
//  constrain(ahrs(2),PI);

/*
  axpy_prod( H, ahrs_, tempv3, true);
  std::cout << "AHRS 1" << std::endl << std::endl;
  tempv3 = ahrs_m - tempv3;
  std::cout << "AHRS 2" << std::endl << std::endl;
  axpy_prod( K, tempv3, tempv6, true);
  std::cout << "AHRS 3" << std::endl << std::endl;
  ahrs = ahrs_ + tempv6;
  std::cout << "AHRS updated" << std::endl << std::endl;
*/


  axpy_prod(K, H, tempa, true);
  tempa = identity_matrix<double>(6) - tempa;
  axpy_prod(tempa, P_, tempb, true);
  axpy_prod(tempb, trans(tempa), P, true);
  axpy_prod(K, R, tempc, true);
  axpy_prod(tempc, trans(K), tempa, true);
  P    = P + tempa;
if (ahrs(0)<0) ahrs(0) = ahrs(0)+2.0*PI;
if (ahrs(0)>2*PI) ahrs(0) = 0;
//  std::cout<<"Corr_AHRS\t"<<ahrs<<std::endl<<std::endl;
//  std::cout<<"Act_AHRS\t"<<ahrs_act<<std::endl<<std::endl;
  ya_f << ahrs(0) << std::endl;
  pi_f << ahrs(1) << std::endl;
  ro_f << ahrs(2) << std::endl;
//  if (i==2000) {
//    for (int j=0; j<500; j++) {
//      tempd = prod(innov[2000-j],trans(innov[2000-j]));
//      temper = temper + tempd;
//    }
//  }
//  i=i+1;
}

void Shutdown() {
  ROS_INFO("Shutting down...");
  ya_f.close();
  pi_f.close();
  ro_f.close();
//  px_f.close();
//  py_f.close();
//  pz_f.close();
//  vx_f.close();
//  vy_f.close();
//  vz_f.close();

  p_i.close();
  q_i.close();
  r_i.close();
  ax_i.close();
  ay_i.close();
  az_i.close();
  magx_i.close();
  magy_i.close();
  magz_i.close();
  Vd_i.close();
  Ve_i.close();
  Vn_i.close();
  ros::shutdown();
}
