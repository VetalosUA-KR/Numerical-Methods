clear;
k=input('PODAJ MAKSYMALN� LICZB� W�Z��W (0 - QUIT) max=');
if (k==0) end
if (k<0) || (k==1) abs2n; end
if (k>1)
for m=2:k
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

err=abs(ywn-abs(5*xt));
errc=abs(ywnc-abs(5*xt));
degr(m)=m;
error(m,1)=max(err);
error(m,2)=max(errc);

bar(degr,error);

legend(' blad wielomianu Lagrange-a','blad wielomianu Czebyszewa');
end
abs2n;
end