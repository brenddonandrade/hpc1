#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3
#define P 4

void imprime_vetor(double *v, int l) {
  int i;

  printf("\nVetor:\n");
  printf("|");
  for (i = 0; i < l; i++) {
    printf("\t%.2lf\t", v[i]);
  }
  puts("|");

  printf("\n");
}

// Metodo de Range kuta de ordem superior
// Pode ser aplicado em EDP de qualquer ordem
// N é o número de equacoes
// y[0] é a funcao
// y'[1] é a derivada
typedef double (*equacoes)();

// Retornando a derivada
// Tenho tantos termos N quanto a ordem da equacao (maior derivada)
double f0(double x, double *y, double *parametros) { return y[1]; }

double f1(double x, double *y, double *parametros) {
  return -(parametros[0] / parametros[1]) * sin(y[0]) - (parametros[2] * y[1]);
}

double f2(double x, double *y, double *parametros) {
  return -(1 / 2 * parametros[3] * pow(parametros[1], 2) * pow(y[1], 2)) +
         (parametros[3] * parametros[0] * parametros[1]) * (1 - cos(y[0]));
}

void metodo_runge_kutta(double x, double *y, double *parametros, double h) {
  int i;
  equacoes f[N] = {f0, f1, f2};
  double k1[N], k2[N], k3[N], k4[N], yp[N], ypp[N];

  for (i = 0; i < N; i++) {
    k1[i] = f[i](x, y, parametros);
    yp[i] = y[i] + ((h / 2.0) * k1[i]);
  }

  for (i = 0; i < N; i++) {
    k2[i] = f[i](x + h / 2.0, yp, parametros);
    ypp[i] = y[i] + (h / 2.0) * k2[i];
  }

  for (i = 0; i < N; i++) {
    k3[i] = f[i](x + (h / 2.0), ypp, parametros);
    yp[i] = y[i] + (h * k3[i]);
  }

  for (i = 0; i < N; i++) {
    k4[i] = f[i](x + h, yp, parametros);
    y[i] = y[i] + (h / 6) * (k1[i] + (2 * k2[i]) + (2 * k3[i]) + k4[i]);
  }
}

// parametros argv[...])
int main(void) {
  int i, cont;
  double a, b, parametros[P], comprimento, massa, gravidade, amortecimento, h,
      x, y1[N], y2[N], y3[N], y4[N];
  FILE *arquivo_teta, *arquivo_omega, *arquivo_energia;

  arquivo_teta = fopen("arquivo-teta.dat", "w");
  arquivo_omega = fopen("arquivo-omega.dat", "w");
  arquivo_energia = fopen("arquivo-energia.dat", "w");

  // Parametros
  gravidade = 9.8;
  comprimento = 1;
  amortecimento = 0.5;
  massa = 1;

  // VI
  y1[1] = y2[1] = y3[1] = y4[1] = 0;
  y1[0] = M_PI * 10 / 180;
  y2[0] = M_PI * 45 / 180;
  y3[0] = M_PI * 90 / 180;
  y4[0] = M_PI * 170 / 180;

  parametros[0] = gravidade;
  parametros[1] = comprimento;
  parametros[2] = amortecimento * comprimento;
  parametros[3] = massa;

  a = 0;
  b = 20;
  h = 0.00001;
  cont = (b-a)/h;
  
  x=a;
  #pragma omp parallel for private(i)
  for (i=0; i<cont ; i++) {
    
    metodo_runge_kutta(x, y1, parametros, h);
    metodo_runge_kutta(x, y2, parametros, h);
    metodo_runge_kutta(x, y3, parametros, h);
    metodo_runge_kutta(x, y4, parametros, h);
    fprintf(arquivo_teta, "%lf\t%lf\t%lf\t%lf\t%lf\n", x, y1[0], y2[0], y3[0],
            y4[0]);
    fprintf(arquivo_omega, "%lf\t%lf\t%lf\t%lf\t%lf\n", x, y1[1], y2[1], y3[1],
            y4[1]);
    fprintf(arquivo_energia, "%lf\t%lf\t%lf\t%lf\t%lf\n", x, y1[2], y2[2],
            y3[2], y4[2]);
    x+=h;
  }

  fclose(arquivo_teta);
  fclose(arquivo_omega);

  return 0;
}
