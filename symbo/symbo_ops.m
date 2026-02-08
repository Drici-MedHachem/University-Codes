pkg load symbolic
clc
clear all

syms l1 l2 l3
l = [l1 l2 l3];
l = transpose(l);
H = sym(zeros(3,3));
H(1,:) = [1 0 0];
H(2,:) = [0 1 0];
H(3,:) = [l1 l2 l3];


H_inv = inv(H);
H_inv_trans = transpose(H_inv);
disp(transpose(H) * l);
