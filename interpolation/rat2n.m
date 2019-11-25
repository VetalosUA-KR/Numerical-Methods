clear;
k=input('PODAJ MAKSYMALN� LICZB� W�Z��W (0 - QUIT) max=');
if (k==0) end
if (k<0) || (k==1) rat2n; end
if (k>1)
for m=2:k
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
wn=polyfit(x,y,n);
wnc=polyfit(xc,yc,n);
ywn=polyval(wn,xt);
ywnc=polyval(wnc,xt);

err=abs(ywn-1./(1+100.*xt.*xt));
errc=abs(ywnc-1./(1+100.*xt.*xt));
degr(m)=m;
error(m,1)=max(err);
error(m,2)=max(errc);
end
bar(degr,error);

legend(' blad wielomianu Lagrange-a','blad wielomianu Czebyszewa');
rat2n;
end