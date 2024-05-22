function [dcm] = dcm2_init()
% dcm2_init.m
% function is automatically called at the initialization of dcm2.slx
dcm.T_A=10e-3;
dcm.r_A=0.04;
dcm.r_f=1;
dcm.T_f=0.2;
dcm.Pfi_f0=1;
dcm.Phi_f=[0 1.00];
dcm.i_f=  [0 1.00];
% In case you want to consider saturation
% dcm.Phi_f=[0 0.14 0.27 0.40 0.54 0.66 0.76 0.84 0.90 0.95 1.00 1.03 1.06];
% dcm.i_f=  [0 0.10 0.20 0.30 0.40 0.50 0.60 0.70 0.80 0.90 1.00 1.10 1.20];
dcm.Om_m0=1;
dcm.T_J=0.8;
% Ramp for the excitation voltage:
time=[0 0.5 2];
u_fn=[1 0.5 0.5];
dcm.u_fn=[time',u_fn'];