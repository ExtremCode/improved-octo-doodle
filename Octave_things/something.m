%построение нормали к поверхности в точке
a = -5:0.1:5;
b = -5:0.1:5;
[x,y] = meshgrid(a,b);
z = @(x,y) 20 - x.^2 - y.^2;
x0 = 0;
y0 = -1;
z0 = z(x0,y0);

surf(x,y,z(x,y))
shading interp
hold on

h = 10^(-8);
dzdx = @(x,y) (z(x+h,y) - z(x,y))/h;
dzdy = @(x,y) (z(x,y+h) - z(x,y))/h;
axis equal;
plot3([x0,x0-dzdx(x0,y0)*2],[y0,y0-dzdy(x0,y0)*2],[z0,z0+1*2], 'color', 'red')

%поиск корней функции одной переменной
f = @(x) 1 + (1+sin(x)-cos(x)).^2-(sin(2*x)-cos(2*x)).^2;
x = -10:0.1:10;
plot(x,f(x))
hold on
grid on
xlabel('X')
ylabel('Y')

#plot(x,0.*x)
tic;
solution = [];
for i=-5:0.1:5
  tmp = fzero(f,i);
  [k,l] = find(abs(solution - tmp)<=1e-14);
  if size(l)(2) == 0
    if abs(tmp) <= 5
      solution = cat(2, solution, tmp);
    endif
  endif
endfor

sort(solution);
time = toc;
time = 0.2053;
for i=1:size(solution)(2)
  plot(solution(i),0, 'marker' ,'o')
endfor

%метод ньютона нахождения корня уравнения
h=1e-9;
x = -5:0.1:5;
f = @(x) 1 + (1+sin(x)-cos(x)).^2-(sin(2*x)-cos(2*x)).^2;
dfdx = @(z) (f(z+h)-f(z))/h;
solution = [];
tic;
for i = -5:5
  xn = i;
  xn_1 = xn-f(xn)/dfdx(xn);
  while abs(xn_1 - xn) > 1e-14
    xn = xn_1;
    xn_1 = xn-f(xn)/dfdx(xn);
  endwhile
  [k,l] = find(abs(solution - xn_1)<=1e-14);
  if size(l)(2) == 0
    if abs(xn_1) <= 5
      solution = cat(2, solution, xn_1);
    endif
  endif
end
time = toc;
time = 0.0088;
plot(x,f(x));
hold on
grid on
for i=1:size(solution)(2)
  plot(solution(i),f(solution(i)), 'marker' ,'o')
endfor

%division by 2 method
f = @(x) 1 + (1+sin(x)-cos(x)).^2-(sin(2*x)-cos(2*x)).^2;
solution = [];
tic;
for i = -4.7:4.7
  target_x = i;
  left_x = target_x-0.1;
  right_x = target_x+0.1;
  while f(left_x) > 0
    left_x -= 0.1;
  endwhile

  while f(right_x) < 0
    right_x += 0.1;
  endwhile

  stop = 100;
  while abs(f(target_x)) > 1e-14 &&stop > 0
    stop -= 1;
    target_x = (left_x + right_x)/2;
    if f(target_x) > 0
      right_x = target_x;
      continue;
    else
      left_x = target_x;
    endif
  endwhile
  solution = [solution, target_x];
end

time = toc;
time = 0.045;
plot(-5:0.1:5,f(-5:0.1:5))
hold on
grid on
for i=1:size(solution)(2)
  plot(solution(i),f(solution(i)), 'marker' ,'o')
endfor

%эволюта кривой
a = 4;
b = 3;
x = @(t) a.*cos(t);
y = @(t) b.*sin(t);
t = 0:0.01:2*pi;
plot(x(t),y(t))
hold on
h = 1e-4;
dx = @(t) (x(t+h)-x(t))/h;
dy = @(t) (y(t+h)-y(t))/h;
d2x = @(t) (-x(t+2*h)+16*x(t+h)-30*x(t)+16*x(t-h)-x(t-2*h))/(12*h^2);
d2y = @(t) (-y(t+2*h)+16*y(t+h)-30*y(t)+16*y(t-h)-y(t-2*h))/(12*h^2);
src_x = [];
src_y = [];
for i=0:0.01:2*pi
  tmpdx = dx(i);
  tmpdy = dy(i);
  tmpd2x = d2x(i);
  tmpd2y = d2y(i);
  src_x = [src_x, x(i)-tmpdy*(tmpdx^2+tmpdy^2)/(tmpdx*tmpd2y-tmpd2x*tmpdy)];
  src_y = [src_y, y(i)-tmpdx*(tmpdx^2+tmpdy^2)/(tmpdx*tmpd2y-tmpd2x*tmpdy)];
end
comet(src_x, src_y)

%эвольвента кривой
x = @(t) (a^2-b^2)/a*cos(t).^3;
y = @(t) (b^2-a^2)/b*sin(t).^3;
src_x = [];
src_y = [];
for i=0:0.01:2*pi
  tmpdx = dx(i);
  tmpdy = dy(i);
  src_x = [src_x, x(i)-tmpdx*(i-a)];
  src_y = [src_y, y(i)-tmpdy*(i-a)];
end
comet(src_x, src_y)

%рисование змейки по синусоиде
x = -10:0.1:10;
#h = plot(x,y);
x_0 = 0;
y_0 = 0;
rad = 0.5;

phi = linspace(0,2*pi,126);
x = [];
y = [];
plots = [];
hold on
for i=1:5
  x = x_0+rad*cos(phi);
  y = y_0+rad*sin(phi);
  plots = [plot(x,y, 'color','green', 'linewidth',2), plots];
  x_0 = x_0 + 2*rad;
endfor
pause(1)
%axis([-10, 100, -5, 5]);
x_0 = 0;
y_0 = 0;
for i=1:50
  for j=1:n
    x_0 = x_0+2*rad;
    y_0 = sin(x_0);
    x = x_0+rad*cos(phi);
    y = y_0+rad*sin(phi);
    set(plots(j),'XData', x, 'YData', y);
  endfor
  drawnow
  pause(0.2)
endfor

%рисование змейки по кривой
f = @(x) 1 + (1+sin(x)-cos(x)).^2-(sin(2.*x)-cos(2.*x)).^2;
x = -10:0.1:10;
plot(x,f(x))
x_0 = -10;
y_0 = f(x_0);
rad = 0.2;
phi = linspace(0,2*pi,126);
x = [];
y = [];
plots = [];
hold on
df = @(t) (f(t+1e-14)-f(t))/1e-14;
coef = @(t) t + 2*rad/sqrt(1+((df(t+rad)+df(t+rad/2)+df(t))/3)^2);
for i=1:5
  disp(x_0)
  x = x_0+rad*cos(phi);
  y = y_0+rad*sin(phi);
  plots = [plot(x,y, 'color','green', 'linewidth',2), plots];
  x_0 = coef(x_0);
  y_0 = f(x_0);
endfor
pause(2)
for i=1:27
  for j=1:5
    x_0 = coef(x_0);
    y_0 = f(x_0);
    x = x_0+rad*cos(phi);
    y = y_0+rad*sin(phi);
    set(plots(j),'XData', x, 'YData', y);
  endfor
  drawnow
  pause(0.3)
endfor

# mathematical pendulum
function dydt = twofunc(t,y)
  dydt(1) = y(2);
  dydt(2) = -9.8/1*sin(y(1));
  dydt = dydt'; %transposing
end
# phi'' + g/L*sin(phi) = 0
[t,Y] = ode45(@twofunc, [0,20],[-pi/2,pi/2]);

x = 0;
y = 0;
x0 = 0;
y0 = 1;
line = plot([x0,x], [y0,y]);
hold on
p = plot(x,y);
axis tight
axis([-1,1,-0.5,1])
phi = [linspace(-pi/2,pi/2,100),linspace(pi/2,-pi/2,100)];
for i=1:400
  x = -sin(Y(mod(i,68),1)) + x0;
  y = -cos(Y(mod(i,68),1)) + y0;
  set(p,'XData', x, 'YData', y,'color', 'green', 'marker', 'o', 'markersize', 20);
  set(line, 'XData', [x0,x], 'YData', [y0,y],'color', 'yellow','Linewidth', 2)
  drawnow
  pause(0.3)
endfor