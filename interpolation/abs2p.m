clear;
m=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) abs2p; end
if (m>1)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=abs(5*x);
for i=0:n
   xc(i+1)=cos((2*i+1)*pi/(2*n+2));
end;
yc=abs(5*xc);
step2=(b-a)/100;
xt=a:step2:b;
wn=polyfit(x,y,n);
wnc=polyfit(xc,yc,n);
ywn=polyval(wn,xt);
ywnc=polyval(wnc,xt);
for i=1:101
	error(i,1)=abs(ywn(i)-abs(5*xt(i)));
	error(i,2)=abs(ywnc(i)-abs(5*xt(i)));
end;
bar(xt,error);
legend('blad wielomianu Lagrange-a','blad wielomianu Czebyszewa');
abs2p;
end