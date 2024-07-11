% load test data of an RGB-D image
% X: data matrix of a point cloud 640x848
% I: rgb image 480x640

load('TestDataRealsense_1.mat');

% get rid of points with zero depth Z values
XX=find(X(:,3));
X=X(XX,:);

% get sizes of data
N = size(X,1);
width = size(I,2);
height = size(I,1);
N_I=width*height;

% show point cloud 
figure(1),plot3(X(:,1),X(:,3),-X(:,2),'.'); hold on;
            grid on
            hold off;
            view([45 30]);
            min_X=min(X(:,1));
            max_X=max(X(:,1));
            min_Y=min(X(:,2));
            max_Y=max(X(:,2));
            min_Z=min(X(:,3));
            max_Z=max(X(:,3));
            xlim([min_X max_X]);
            ylim([min_Z max_Z]);
            zlim([-max_Y -min_Y]);
            xlabel('X');
            ylabel('Z');
            zlabel('Y');
            
% show RGB image

figure(2),imshow(I);

% mean value of point cloud

m=X'*ones(N,1)/N;

% data covariance of point cloud

%S=(X'*X)/N-m*m'


% create a Kd Tree
KdTree = KDTreeSearcher(X);
% find K nearest neighbors
K=100;
Idx = knnsearch(KdTree,m','K',K);
M=ones(K,3);
M(:,1:2)=X(Idx',1:2);
b(:,1)=X(Idx',3);
% compute parameters using pseudoinverse
w=inv(M'*M)*M'*b 
%w = (M'*M) \ (M'*b)
% calculate pseudoinverse via SVD
[U,S,V]=svd(M);
Sp=inv(S'*S)*S';
Mp=V*Sp*U';
w=Mp*b
normal(1,1)=w(1,1)/sqrt(w(1,1)^2+w(2,1)^2+1);
normal(2,1)=w(2,1)/sqrt(w(1,1)^2+w(2,1)^2+1);
normal(3,1)=-1/sqrt(w(1,1)^2+w(2,1)^2+1);
normal
d=w(3,1)/sqrt(w(1,1)^2+w(2,1)^2+1)


ptCloud = pointCloud(X);
normals = pcnormals(ptCloud,12);
figure(15),plot3(normals(:,1),normals(:,2),normals(:,3),'.');

figure(16),subplot(1,3,1),histogram(normals(:,1),100);
subplot(1,3,2),histogram(normals(:,2),100);
subplot(1,3,3),histogram(normals(:,3),100);

figure(5),plot3(X(:,1),X(:,3),-X(:,2),'b.'); hold on;
          plot3(X(Idx,1),X(Idx,3),-X(Idx,2),'r*');
            grid on
            hold off;
            view([45 30]);
            min_X=min(X(:,1));
            max_X=max(X(:,1));
            min_Y=min(X(:,2));
            max_Y=max(X(:,2));
            min_Z=min(X(:,3));
            max_Z=max(X(:,3));
            xlim([min_X max_X]);
            ylim([min_Z max_Z]);
            zlim([-max_Y -min_Y]);
            xlabel('X');
            ylabel('Z');
            zlabel('Y');