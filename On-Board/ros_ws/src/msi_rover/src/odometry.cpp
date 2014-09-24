#define PI 3.14159265359
#define GG 9.8
#define _DEBUG_

#include <odometry.hpp>

#ifdef _DEBUG_
#include <fstream>
#include <iostream>
std::ofstream y_f, p_f, r_f, x_f, y_f, z_f, vx_f, vy_f, vz_f;
#endif

matrix<float> P (6,6);
matrix<float> Q (6,6);
matrix<float> R (3,3);
matrix<float> H (3,6);
vector<float> ahrs    (6);
vector<float> ins     (6);

void Load() {
  y_f.open("yaw_const1");
  p_f.open("pitch_const1");
  r_f.open("roll_const1");
  x_f.open("yaw_const1");
  y_f.open("pitch_const1");
  z_f.open("roll_const1");
  vx_f.open("yaw_const1");
  vy_f.open("pitch_const1");
  vz_f.open("roll_const1");
  ahrs(0) = 0.1;
  ahrs(1) = 0.1;
  ahrs(2) = 0.1;
  ahrs(3) = 0.01;
  ahrs(4) = 0.01;
  ahrs(5) = 0.01;

  vel(0) = 0;
  vel(1) = 0;
  vel(2) = 0;

  acc(0) = 0;
  acc(1) = 0;
  acc(2) = (-1)*GG;

  gps_vel(0) = 0;
  gps_vel(1) = 0;
  gps_vel(2) = 0;

  P(0,0) = 25;
  P(0,1) =  0;
  P(0,2) =  0;
  P(0,3) =  0;
  P(0,4) =  0;
  P(0,5) =  0;
  P(1,0) =  0;
  P(1,1) = 25;
  P(1,2) =  0;
  P(1,3) =  0;
  P(1,4) =  0;
  P(1,5) =  0;
  P(2,0) =  0;
  P(2,1) =  0;
  P(2,2) = 25;
  P(2,3) =  0;
  P(2,4) =  0;
  P(2,5) =  0;
  P(3,0) =  0;
  P(3,1) =  0;
  P(3,2) =  0;
  P(3,3) =  0.25;
  P(3,4) =  0;
  P(3,5) =  0;
  P(4,0) =  0;
  P(4,1) =  0;
  P(4,2) =  0;
  P(4,3) =  0;
  P(4,4) =  0.25;
  P(4,5) =  0;
  P(5,0) =  0;
  P(5,1) =  0;
  P(5,2) =  0;
  P(5,3) =  0;
  P(5,4) =  0;
  P(5,5) =  0.25;

  Q(0,0) = 0.1;
  Q(0,1) = 0;
  Q(0,2) = 0;
  Q(0,3) = 0;
  Q(0,4) = 0;
  Q(0,5) = 0;
  Q(1,0) = 0;
  Q(1,1) = 0.1;
  Q(1,2) = 0;
  Q(1,3) = 0;
  Q(1,4) = 0;
  Q(1,5) = 0;
  Q(2,0) = 0;
  Q(2,1) = 0;
  Q(2,2) = 0.1;
  Q(2,3) = 0;
  Q(2,4) = 0;
  Q(2,5) = 0;
  Q(3,0) = 0;
  Q(3,1) = 0;
  Q(3,2) = 0;
  Q(3,3) = 0.001;
  Q(3,4) = 0;
  Q(3,5) = 0;
  Q(4,0) = 0;
  Q(4,1) = 0;
  Q(4,2) = 0;
  Q(4,3) = 0;
  Q(4,4) = 0.001;
  Q(4,5) = 0;
  Q(5,0) = 0;
  Q(5,1) = 0;
  Q(5,2) = 0;
  Q(5,3) = 0;
  Q(5,4) = 0;
  Q(5,5) = 0.001;

  R(0,0) = 10;
  R(0,1) = 0;
  R(0,2) = 0;
  R(1,0) = 0;
  R(1,1) = 5;
  R(1,2) = 0;
  R(2,0) = 0;
  R(2,1) = 0;
  R(2,2) = 1;

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

  p=0;
  q=0;
  r=0;
  Mx=0.00026;
  My=0;
  Mz=0;
}

void Loop() {
//-----------------------//
//---- Process Model ----//
//-----------------------//

//-- State Prediction ---//            //uses ahrs, p, q, r, dt
                                       //updates ahrs_dot, ahrs_
  vector<float> ahrs_dot (6);
  vector<float> ahrs_ (6);

  ahrs_dot(0) = (q + ahrs(4))*sin(ahrs(2))/cos(ahrs(1)) + (r + ahrs(5))*cos(ahrs(2))/cos(ahrs(1));
  ahrs_dot(1) = (q + ahrs(4))*cos(ahrs(2))              - (r + ahrs(5))*sin(ahrs(2));
  ahrs_dot(2) = (q + ahrs(4))*sin(ahrs(2))*tan(ahrs(1)) - (r + ahrs(5))*cos(ahrs(2))*tan(ahrs(1)) + (p + ahrs(3));
  ahrs_dot(3) = 0;
  ahrs_dot(4) = 0;
  ahrs_dot(5) = 0;
  ahrs_       = ahrs + ahrs_dot * del_t;
//  std::cout << "ahrs_d\t" << ahrs_dot << std::endl << std::endl;
//  std::cout << "ahrs\t" << ahrs << std::endl << std::endl;
//  std::cout << "ahrs_\t" << ahrs_ << std::endl << std::endl;

//--- Velocity Update ---//            //uses ahrs_, gps_vel, vel, dt
                                       //updates vel, v_dot, Rot
  matrix<float> Rot (3,3);
  vector<float> v_dot;
  vector<float> prev_v;

  Rot(0,0) = cos(ahrs_(2))*cos(ahrs_(1));
  Rot(0,1) = sin(ahrs_(2))*cos(ahrs_(1));
  Rot(0,2) = sin(ahrs_(1))*(-1);
  Rot(1,0) = sin(ahrs_(2))*sin(ahrs_(1))*cos(ahrs_(0)) - cos(ahrs_(2))*sin(ahrs_(0));
  Rot(1,1) = sin(ahrs_(2))*sin(ahrs_(1))*sin(ahrs_(0)) + cos(ahrs_(2))*cos(ahrs_(0));
  Rot(1,2) = sin(ahrs_(2))*cos(ahrs_(1));
  Rot(2,0) = cos(ahrs_(2))*sin(ahrs_(1))*cos(ahrs_(0)) + sin(ahrs_(2))*sin(ahrs_(0));
  Rot(2,1) = cos(ahrs_(2))*sin(ahrs_(1))*sin(ahrs_(0)) - sin(ahrs_(2))*cos(ahrs_(0));
  Rot(2,2) = cos(ahrs_(2))*cos(ahrs_(1));

  prev_v = vel;
  vel    = prod(Rot, gps_vel);
  v_dot  = (vel - prev_v)/del_t;
//  std::cout << "vel\t" << vel << std::endl << std::endl;
//  std::cout << "vel_d\t" << v_dot << std::endl << std::endl;

//-----------------------//
//-- Measurement Model --//
//-----------------------//
  vector<float> ahrs_m (3);

//----- Measure Yaw -----//            //uses Mx, My, Mz, ahrs
                                       //updates Mx_h, My_h, ahrs_m(0)
  float My_h, Mx_h;

  Mx_h      = Mx*cos(ahrs(1)) + My*sin(ahrs(2))*sin(ahrs(1)) + Mz*cos(ahrs(2))*sin(ahrs(1));
  My_h      = My*cos(ahrs(2)) + Mz*sin(ahrs(2));
  ahrs_m(0) = atan2(My_h, Mx_h);

//---- Measure Pitch ----//            //uses acc, vel, v_dot, p, q, r, ahrs_, g
                                       //updates ahrs_m(1)
  ahrs_m(1) = ( acc(0) - v_dot(0) + (r + ahrs_(5))*vel(1) - (q + ahrs_(4))*vel(2) ) / GG;
  if      (ahrs_m(1) > 1) ahrs_m(1) =  PI/2;
  else if (ahrs_m(1) > 1) ahrs_m(1) = -PI/2;
  else                    ahrs_m(1) =  sin(ahrs_m(1));

//---- Measure Roll -----//            //uses acc, vel, v_dot, p, q, r, ahrs_
                                       //updates ahrs_m(2)
  ahrs_m(2) = atan2( ( acc(1) - v_dot(1) + (p + ahrs_(3))*vel(2) - (r + ahrs_(5))*vel(0) ),
                     ( acc(2) - v_dot(2) + (q + ahrs_(4))*vel(0) - (p + ahrs_(3))*vel(1) ) );
  ahrs_m(2) = (ahrs_m(2)>PI/2.0)?(ahrs_m(2)-PI):ahrs_m(2);
//  std::cout << "ahrs_m" << ahrs_m << std::endl << std::endl;
//-- Update Covariance --//            //uses ahrs, p, q, r, P, Q
                                       //updates T, F, P_
  matrix<float> T  (6,6);
  matrix<float> F  (6,6);
  matrix<float> P_ (6,6);

  T(0,0) = 0;
  T(0,1) = sin(ahrs(2))/cos(ahrs(1));
  T(0,2) = cos(ahrs(2))/cos(ahrs(1));
  T(0,3) = 0;
  T(0,4) = 0;
  T(0,5) = 0;
  T(1,0) = 0;
  T(1,1) = cos(ahrs(2));
  T(1,2) = sin(ahrs(2));
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

  F(0,0) = 0;
  F(0,1) = sin(ahrs(1))*( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) ) / pow(cos(ahrs(1)),2);
  F(0,2) = ( (q + ahrs(4))*cos(ahrs(2)) - (r + ahrs(5))*sin(ahrs(2)) ) / cos(ahrs(1));
  F(0,3) = 0;
  F(0,4) = sin(ahrs(2))/cos(ahrs(1));
  F(0,5) = cos(ahrs(2))/cos(ahrs(1));
  F(1,0) = 0;
  F(1,1) = 0;
  F(1,2) = (-1)*( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) );
  F(1,3) = 0;
  F(1,4) = cos(ahrs(2));
  F(1,5) = (-1)*sin(ahrs(2));
  F(2,0) = 0;
  F(2,1) = ( (q + ahrs(4))*sin(ahrs(2)) + (r + ahrs(5))*cos(ahrs(2)) ) / pow(cos(ahrs(1)),2);
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
  
  matrix<float> tempa (6,6);
  matrix<float> tempb (6,6);
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
  matrix<float> K      (6,3);
  matrix<float> tempc  (6,3);
  matrix<float> tempd  (3,3);
  matrix<float> tempe  (3,3);
  vector<float> tempv3 (3);
  vector<float> tempv6 (6);

  axpy_prod(P_, trans(H), tempc, true);
  axpy_prod( H, tempc, tempd, true);
  tempd = tempd + R;
  inv(tempd, tempe);
  axpy_prod(tempc, tempe, K, true);
//  std::cout << K << std::endl << std::endl;

  tempv3 = ahrs_m - prod(H, ahrs_);
  ahrs   = ahrs_ + prod(K, tempv3);

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
  tempa = identity_matrix<float>(6) - tempa;
  axpy_prod(tempa, P_, tempb, true);
  axpy_prod(tempb, trans(tempa), P, true);
  axpy_prod(K, R, tempc, true);
  axpy_prod(tempc, trans(K), tempa, true);
  P    = P + tempa;

  if (ahrs(0) < 0) ahrs(0) = ahrs(0) + 2*PI;
  if (ahrs(0) > 2*PI) ahrs(0) = 0;
  std::cout<<"FINAL\t"<<ahrs<<std::endl<<std::endl;
  yaw   << ahrs(0) << ", ";
  pitch << ahrs(1) << ", ";
  roll  << ahrs(2) << ", ";
}
