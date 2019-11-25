clear;
k=input('PODAJ LICZB� W�Z��W (0 - QUIT) m=');
if (k==0) end
if (k<0) || (k==1)  || (k==2) rat3n; end
if (k>2)
for m=3:k
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

errc=abs(ywnc-1./(1+100.*xt.*xt));
errs=abs(ysp-1./(1+100.*xt.*xt));
degr(m)=m;
error(m,1)=max(errc);
error(m,2)=max(errs);
end
bar(error);

legend('blad wielomianu Czebyszewa','blad splajnow');
rat3n;
end