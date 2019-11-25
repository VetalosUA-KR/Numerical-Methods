clear;
m=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (m==0) end
if (m<0) || (m==1) || (m==2) rat3p; end
if (m>2)
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=1./(1+100.*x.*x);
for i=0:n
   xc(i+1)=cos((2*i+1)*pi/(2*n+2));
end;
yc=1./(1+100.*xc.*xc);
step2=(b-a)/100;
xt=a:step2:b;
wnc=polyfit(xc,yc,n);
ywnc=polyval(wnc,xt);
ysp=spline(x,y,xt);
for i=1:101
	error(i,1)=abs(ywnc(i)-1./(1+100.*xt(i).*xt(i)));
	error(i,2)=abs(ysp(i)-1./(1+100.*xt(i).*xt(i)));
end;
bar(xt,error);
legend('blad wielomianu Czebyszewa','blad splajnow');
rat3p;
end