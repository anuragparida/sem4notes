Img1=imread('Auge.jpg','jpg');
Img2=imread('Auge2.jpg','jpg');

% gray value image
G=(sum(Img1,3)/3);
N=size(G,1)*size(G,2);

figure(1),imagesc(G);axis off; colormap gray;

% auto correlation

c=imfilter(G,G,'circular');
c=c/N;
figure(2),imagesc(c);axis off; colormap gray;colorbar

% Autokovarianzfunktion im Ortsraum

mG=mean2(G);
%mG=1/N*sum(sum(G))
s=c-mG^2;
%s=imfilter((G-mG),(G-mG),'circular');
%s=s/N;
figure(3),imagesc(s);axis off; colormap gray;colorbar

% Normierte Autokovarianzfunktion im Ortsraum

sG=std2(G)
%sGt=sqrt(1/(N-1)*sum(sum((G-mGt).^2)))
%sGtt=sqrt(1/(N-1)*sum(sum(G.^2))-N/(N-1)*mGt^2)
r=s/(sG^2);
%r=imfilter((G-mG)/sG,(G-mG)/sG,'circular');
%r=r/N;
figure(4),imagesc(r);axis off; colormap gray;colorbar

% Kreuzkorrelation

H2=(sum(Img2,3)/3);
G2 = imresize(H2(47:392,47:392), [size(G,1) size(G,2)]);
figure(5),imagesc(G2);axis off; colormap gray;

% Kreuzkorrelationsfunktion im Ortsraum

c2=imfilter(G2,G,'circular');
c2=c2/N;
figure(6),imagesc(c2);axis off; colormap gray;colorbar

% Autokovarianzfunktion im Ortsraum

mG2=mean2(G2);

s2=c2-mG*mG2;
%s2=imfilter((G-mG),(G2-mG2),'circular');
%s2=s2/N;
figure(7),imagesc(s2);axis off; colormap gray;colorbar

% Normierte Autokovarianzfunktion im Ortsraum

sG2=std2(G2);
%sG2=sqrt(1/(N-1)*sum(sum((G2-mG2).^2)))
%sG2=sqrt(1/(N-1)*sum(sum(G2.^2))-N/(N-1)*mG2^2)
 
r2=s2/(sG*sG2);
figure(8),imagesc(r2);axis off; colormap gray;colorbar

%r2 = normxcorr2(G,H);
%figure(6),imagesc(r2);axis off; colormap gray;colorbar

% Template Matching
H = G(133:161,146:176);
NN=size(H,1)*size(H,2);
figure(9),imagesc(H);axis off; colormap gray;

% lokale Kreuzkorrelationsfunktion im Ortsraum

c3=imfilter(G,H,'circular');
c3=c3/NN;
figure(10),imagesc(c3);axis off; colormap gray;colorbar

% Autokovarianzfunktion im Ortsraum
box=1/NN*ones(size(H));
mG3=imfilter(G,box,'circular');
mH=mean2(H)

%s=imfilter((G-mG),(H-mH),'circular');
%s=s/N;
s3=c3-mG3.*mH;
figure(11),imagesc(s3);axis off; colormap gray;colorbar

% Normierte Autokovarianzfunktion im Ortsraum
box2=1/((size(H,1)-1)*(size(H,2)-1))*ones(size(H));
sG=imfilter((G-mG3).^2,box2,'circular');%std2(G)
sH=std2(H)
%sGt=sqrt(1/(N-1)*sum(sum((G-mGt).^2)))
%sGtt=sqrt(1/(N-1)*sum(sum(G.^2))-N/(N-1)*mGt^2)
 
%s=imfilter((G-mG)/sG,(G-mG)/sG,'circular');
%s=s/N;
r3=s3./(sqrt(sG).*sH);
figure(12),imagesc(r,[-0.7 1]);axis off; colormap gray;colorbar

%r3 = normxcorr2(G,H);
