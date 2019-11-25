clear;
k=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (k==0) end
if (k<0) || (k==1) || (k==2) abs3n; end
if (k>2)
for m=3:k
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
wnc=polyfit(xc,yc,n);
ywnc=polyval(wnc,xt);
ysp=spline(x,y,xt);

errc=abs(ywnc-abs(5*xt));
errs=abs(ysp-abs(5*xt));
degr(m)=m
error(m,1)=max(errc)
error(m,2)=max(errs)
end
bar(error);

legend('blad wielomianu Czebyszewa','blad splajnow');
abs3n;
end