close all
clear all

%%%% ground truth line %%%%
%%%% n_1x+n_2y-d=0 %%%%
%%%% y = mx + t %%%%

alpha=pi/2+pi/4;
n=[sin(alpha);cos(alpha)];
d=3;

m=-n(1,1)/n(2,1);
t=d/n(2,1);

x=[-5:0.2:5];
y=m.*x+t;
N=size(x,2);

figure(1),plot(x,y,'go');hold on;

gain=0.8;
X(:,1)=x'+gain*randn(N,1);
X(:,2)=y'+gain*randn(N,1);
X(:,3)=ones(N,1);

plot(X(:,1),X(:,2),'r+');hold on;

%%%% measurement statistics %%%%

M=X'*X/N
mu=M(1:2,3)

%%%% least squares estimate %%%%

A(1,1)=M(1,1);
A(1,2)=M(1,3);
A(2,1)=A(1,2);
A(2,2)=1;
b(1,1)=M(1,2);
b(2,1)=M(2,3);

est_1=A\b;

% empirical correlation coefficient
CC=corrcoef(X(:,1),X(:,2));
quality_1=abs(CC(1,2))
% root-mean-square error
error_1=sqrt(sum((est_1(1,1)*X(:,1)+est_1(2,1)-X(:,2)).^2)/N)

%%%% best fit linear subspace %%%%

[U,S,V]=svd(M);
est_2=V(:,3)./sqrt(V(1,3)^2+V(2,3)^2);
if est_2(3,1)>0,
    est_2=-est_2;
end

% quality estimate = inverse of the condition number
quality_2=S(3,3)/S(1,1)
% remaining error
error_2=sqrt(sum((X(:,1:2)*est_2(1:2,1)+est_2(3,1)).^2,1)/N)

%%%% best fit linear subspace PCA %%%%

%AA(1,1)=M(1,1)-M(1,3)^2;
%AA(1,2)=M(1,2)-M(1,3)*M(2,3);
%AA(2,1)=AA(1,2);
%AA(2,2)=M(2,2)-M(2,3)^2;
%[VV,DD] = eig(AA);
%est_3(1:2,1)=VV(:,1);
%est_3(3,1)=-(VV(1,1)*M(1,3)+VV(2,1)*M(2,3));
%[UU,SS,VV]=svd(AA);
%est_3(1:2,1)=VV(:,2);
%est_3(3,1)=-(VV(1,2)*M(1,3)+VV(2,2)*M(2,3));

% data covariance matrix
Xnorm=(X(:,1:2)-ones(N,1)*sum(X(:,1:2),1)/N);
COV=Xnorm'*Xnorm/N;
[VV,DD] = eig(COV);
est_3(1:2,1)=VV(:,1);
est_3(3,1)=-(VV(1,1)*M(1,3)+VV(2,1)*M(2,3));
% quality estimate = inverse of the condition number
quality_3=DD(1,1)/DD(2,2)
% remaining error
error_3=sqrt(sum((X(:,1:2)*est_3(1:2,1)+est_3(3,1)).^2,1)/N)

% square-root-of-distances from least-squares estimate
est_4(1,1)=sin(atan(-est_1(1,1)));
est_4(2,1)=cos(atan(-est_1(1,1)));
est_4(3,1)=-est_1(2,1)*est_4(2,1);
error_4=sqrt(sum((X(:,1:2)*est_4(1:2,1)+est_4(3,1)).^2,1)/N)


plot(X(:,1),est_1(1,1)*X(:,1)+est_1(2,1),'b');hold on;
plot(X(:,1),-(est_2(1,1)/est_2(2,1))*X(:,1)-(est_2(3,1)/est_2(2,1)),'c');hold on;
plot(X(:,1),-(est_3(1,1)/est_3(2,1))*X(:,1)-(est_3(3,1)/est_3(2,1)),'r');hold on;

proj_points=X(:,1:2)-(X(:,1:2)*est_3(1:2,1)+est_3(3,1))*est_3(1:2,1)';
plot(proj_points(:,1),proj_points(:,2),'g+');
legend('ground truth','noisy measures','least-squares','subspace','subspace-norm','improved measures')
axis equal

figure(2),
%stem(X(:,1),abs(est_1(1,1)*X(:,1)+est_1(2,1)-X(:,2)),'b');hold on;
stem(X(:,1),abs(X(:,1:2)*est_4(1:2,1)+est_4(3,1)),'b');hold on;
stem(X(:,1),abs(X(:,1:2)*est_2(1:2,1)+est_2(3,1)),'c');hold on;
stem(X(:,1),abs(X(:,1:2)*est_3(1:2,1)+est_3(3,1)),'r');

legend('least-squares','subspace','subspace-norm')