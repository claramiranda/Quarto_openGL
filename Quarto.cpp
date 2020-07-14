// Faculdade de Tecnologia - Universidade Estadual de Campinas
// Trabalho final de Computação Gráfica - 1o semestre 2020
// Clara Anna Miranda - 155041
// Katherine Rocha - 106768
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "image.h"

//declaracao de constantes
#define TEXTURA_DO_POSTER "img/yurionice.rgb"
#define TEXTURA_DO_HAIKYUU "img/haikyuu.rgb"
#define TEXTURA_NARUTO "img/naruto.rgb"
#define TEXTURA_KIMETSU "img/kimetsu.rgb"
#define TEXTURA_EVANGELION "img/evangelion.rgb"

#define TEXTURA_COBERTOR "img/cobertor.rgb"
#define TEXTURA_PORTA "img/door.rgb"

#define TEXTURA_DO_CHAO "img/chao.rgb"
#define TEXTURA_MADEIRA "img/madeira.rgb"
#define TEXTURA_DO_MONITOR "img/ft.rgb"
#define TEXTURA_UNICAMP "img/unicamp.rgb"

//testes mover maca
int PASSOS = 0;
float macaX, macaY, macaZ;
float taloX, taloY, taloZ;


#define PI 3.1415
GLfloat tetaxz = 0;
GLfloat raioxz = 6;
GLfloat obs[3] = { 0.0,7.0,0.0 };
GLfloat look[3] = { 0.0,3.0,0.0 };
GLint movemaca = 0;
GLint direcao = 1;


//variaveis de textura
GLuint  textura_chao;
GLuint  textura_cobertor;
GLuint  textura_porta;
GLuint  textura_poster;
GLuint  textura_haikyuu;
GLuint  textura_naruto;
GLuint  textura_monitor;
GLuint  textura_unicamp;
GLuint  textura_evangelion;
GLuint  textura_kimetsu;


//var mudanca perspectiva
static int rodatudo = 0;

//mapeamento de texturas
GLfloat planotext[4][2]={
  {-1,-1},
  {+1,-1},
  {+1,+1},
  {-1,+1}
};

GLfloat cobertortext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

GLfloat portatext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

GLfloat postertext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

GLfloat monitortext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

GLfloat unicamptext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

//parametros de iluminacao
//moldura poster naruto 
GLfloat naruto_difusa[]    = { 0.0, 0.2, 0.3, 1.0 };
GLfloat naruto_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat naruto_brilho[]    = { 60.0 };

//moldura poster haikyuu 
GLfloat haikyuu_difusa[]    = {0.7, 0.3, 0.0, 1.0 };
GLfloat haikyuu_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat haikyuu_brilho[]    = { 60.0 };

//moldura poster Yuri on Ice
GLfloat yoi_difusa[]    = { 0.4, 0.4, 1.0, 1.0 };
GLfloat yoi_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat yoi_brilho[]    = { 60.0 };

//cor de madeira
GLfloat madeira_difusa[]    = { 0.5, 0.0, 0.0, 1.0 };
GLfloat madeira_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat madeira_brilho[]    = { 30.0 };

//preto
GLfloat computador_difusa[]    = { 0.0, 0.0, 0.0, 1.0 };
GLfloat computador_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat computador_brilho[]    = { 50.0 };

//vermelho
GLfloat vermelho_difusa[]    = { 1.0, 0.0, 0.0, 1.0 };
GLfloat vermelho_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat vermelho_brilho[]    = { 50.0 };

//cinza
GLfloat chaleira_difusa[]    = { 0.5, 0.5, 0.5, 1.0 };
GLfloat chaleira_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chaleira_brilho[]    = { 50.0 };

//verde
GLfloat verde_difusa[]    = { 0.0, 1.0, 0.0, 1.0 };
GLfloat verde_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat verde_brilho[]    = { 40.0 };

//azul
GLfloat azul_difusa[]    = { 0.0, 0.2, 0.5, 1.0 };
GLfloat azul_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat azul_brilho[]    = { 40.0 };

//branco
GLfloat branco_difusa[]    = { 0.0, 0.5, 0.8, 1.0 };
GLfloat branco_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat branco_brilho[]    = { 15.0 };

//amarelo
GLfloat amarelo_difusa[]    = { 0.5, 0.5, 0.0, 1.0 };
GLfloat amarelo_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat amarelo_brilho[]    = { 65.0 };

//livro
GLfloat livro_difusa[]    = { 0.6, 0.5, 0.0, 1.0 };  //
GLfloat livro_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat livro_brilho[]    = { 40.0 };

//chao 
GLfloat chao_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat chao_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chao_brilho[]    = { 50.0 };

//parametros de iluminacao
GLfloat posicao_luz[]    = { 0.0, 20.0, 0.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.3, 0.3, 0.3, 1.0};

GLint gouraud=0;

void display(void){
	//inicializacao
  	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glDepthMask(GL_TRUE);
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	if(gouraud){
	  glShadeModel(GL_SMOOTH);
	}
	else{
	  glShadeModel(GL_FLAT);
	}
	 
	//Rotate com R ou r
  	glPushMatrix();
	glRotatef ((GLfloat) rodatudo, 0.0, 1.0, 0.0); //Rotate do R 



    //Chão	
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);		//textura
	glBindTexture(GL_TEXTURE_2D,textura_chao);					//textura
	glEnable(GL_TEXTURE_2D);  									//textura
	glBegin(GL_QUADS);											//definicao do plano
		glTexCoord2fv(planotext[0]); glVertex3f(-20,0.5,20);
		glTexCoord2fv(planotext[1]); glVertex3f(20,0.5,20);
		glTexCoord2fv(planotext[2]); glVertex3f(20,0.5,-20);
		glTexCoord2fv(planotext[3]); glVertex3f(-20,0.5,-20);
	glEnd();
	glDisable(GL_TEXTURE_2D); 									//encerra textura
 
 
 
 
  	//Quadro 1: Yuri on Ice 
  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yoi_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yoi_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, yoi_brilho);
	//modelagem da moldura
	glPushMatrix(); 					
		glTranslatef(13.5,15, -20.3);
		glScalef(15,12, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	//aplicacao da textura no plano
  	glEnable(GL_TEXTURE_2D);  
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_poster);
  	//Modelagem do plano que vai segurar a textura
	glBegin(GL_QUADS); 
		glTexCoord2fv(postertext[0]);  glVertex3f(7.5,10,-20);
	  	glTexCoord2fv(postertext[1]);  glVertex3f(20,10,-20);
	 	glTexCoord2fv(postertext[2]);  glVertex3f(20,20,-20);
	 	glTexCoord2fv(postertext[3]);  glVertex3f(7.5,20,-20);
	glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
  	
  	
  	
  	
  	//Quadro 2: Haikyuu
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, haikyuu_difusa); 		//iluminacao da moldura
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, haikyuu_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, haikyuu_brilho);
  	  	//modelagem da moldura
		glPushMatrix();							
			glTranslatef(-10,15, 20.3);
			glScalef(15,12, 0.5);
			glutSolidCube(1.0);
		glPopMatrix();
  		//textura do poster haikyuu
  		glEnable(GL_TEXTURE_2D); 
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  		glBindTexture(GL_TEXTURE_2D,textura_haikyuu);
		//superfice poster haikyuu
	    glBegin(GL_QUADS);
	  		glTexCoord2fv(postertext[0]);  glVertex3f(-2.8,10,20);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(-17,10,20);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(-17,20,20);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(-2.8,20,20);
		glEnd();
  		glDisable(GL_TEXTURE_2D); //encerra textura
  	
  	
  	
  	//Quadro 3: Naruto
  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, naruto_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, naruto_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, naruto_brilho);  	
  		//moldura poster naruto
  		glColor3f(0.5, 0.8, 0.0);
		glPushMatrix();
			glTranslatef(10,15, 20.3);
			glScalef(15,12, 0.5);
			glutSolidCube(1.0);
		glPopMatrix();
  	//textura poster naruto
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_naruto);
	  //superfice poster naruto
	    glBegin(GL_QUADS);
	  		glTexCoord2fv(postertext[0]);  glVertex3f(2.8,10,20);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(17,10,20);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(17,20,20);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(2.8,20,20);
		glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura*/
  	
  	
  	
  	

  	//Quadro 4: Kimetsu no Yaba 
  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yoi_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yoi_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, yoi_brilho);
	//modelagem da moldura
	glPushMatrix(); 			
		glTranslatef(-21,15,12);
		glRotated(90, 0.0, 1.0, 0.0 );		
		glTranslatef(0,0,0);
		glScalef(15,12, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	//aplicacao da textura no plano
  	glEnable(GL_TEXTURE_2D);  
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_kimetsu);
  	//Modelagem do plano que vai segurar a textura
	glBegin(GL_QUADS); 
	  		glTexCoord2fv(postertext[0]);  glVertex3f(-20,10,5);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(-20,10,18);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(-20,20,18);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(-20,20,5);
	glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
  	
  	
  	
  	
  	//Quadro 5: Evangelion 
  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vermelho_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, vermelho_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, vermelho_brilho);
	//modelagem da moldura
	glPushMatrix(); 			
		glTranslatef(21,15,-3);
		glRotated(90, 0.0, 1.0, 0.0 );		
		glTranslatef(0,0,0);
		glScalef(17,12, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	//aplicacao da textura no plano
  	glEnable(GL_TEXTURE_2D);  
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_evangelion);
  	//Modelagem do plano que vai segurar a textura
	glBegin(GL_QUADS); 
	  		glTexCoord2fv(postertext[0]);  glVertex3f(20,10,5);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(20,10,-10);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(20,20,-10);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(20,20,5);
	glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
  	



  	//Cama
  	//iluminacao do colchao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);
		//modelagem do colchao
		glPushMatrix();
			glTranslatef(-10, 2.4, 15.0);
			glScalef(20, 3, 10.0);
			glutSolidCube(1.0);
		glPopMatrix();
		//cobertor
		//textura pcobertor
		glEnable(GL_TEXTURE_2D);  //seta textura
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
		glBindTexture(GL_TEXTURE_2D,textura_cobertor);
		//superfice superior cobertor
	    glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,4,10);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,4,10);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,20);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,20);
		glEnd();
		//superfice frontal cobertor
		glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,0,9.9);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,0,9.9);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,9.9);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,9.9);
		glEnd();
		//superfice costas cobertor
		glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,0,20.1);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,0,20.1);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,20.1);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,20.1);
		glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura*/
  	
  	
  	//Porta
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_porta);
  	  	glBegin(GL_QUADS);
			glTexCoord2fv(portatext[0]);glVertex3f(-20,20,0);
	  		glTexCoord2fv(portatext[1]);glVertex3f(-20,0,0);
	 	 	glTexCoord2fv(portatext[2]);glVertex3f(-20,0,-10);
	 	 	glTexCoord2fv(portatext[3]);glVertex3f(-20,20,-10);
		glEnd();		
	glDisable(GL_TEXTURE_2D); //encerra textura*/
			
			
	 //Cadeira
	//iluminacao cadeira
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
	//perna costas 1
	glPushMatrix();
		glTranslatef(5.0, 5.0, 0.0);
		glScalef(0.5, 8.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//perna costas2
	glPushMatrix();
		glTranslatef(9.0, 5.0, 0.0);
		glScalef(0.5, 8.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();	
	
	//encosto
	glPushMatrix();
		glTranslatef(7.0, 7.0, 0.0);
		glScalef(4.0, 4.0, 0.0);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//assento
	glPushMatrix();
		glTranslatef(7.0, 4.0, -2.0);
		glScalef(5.0, 0.5, 4.0);
		glutSolidCube(1.0);
	glPopMatrix();
	//pernas
	glPushMatrix();
		glTranslatef(5.0, 2.5, -3.5);
		glScalef(0.5, 4.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(9.0, 2.5, -3.5);
		glScalef(0.5, 4.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	
	
	//Mesa
	//iluminacao
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
	//superfice tampo mesa
	glPushMatrix();
		glTranslatef(7.5, 6.5, -5.0);
		glScalef(15.0, 0.5, 8.0);
		glutSolidCube(1.0);
	glPopMatrix();
	//pernas da mesa
	glPushMatrix();
		glTranslatef(0.5, 3.5, -2.0);
		glScalef(0.5, 6.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(14.5, 3.5, -2.0);
		glScalef(0.5, 6.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(14.5, 3.5, -8.0);
		glScalef(0.5, 6.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.5, 3.5, -8.0);
		glScalef(0.5, 6.5, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//computador
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, computador_difusa);			//iluminacao computador
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, computador_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, computador_brilho);
	//modelagem
	glPushMatrix();
		glTranslatef(6.0, 7.0, -5.0);
		glScalef(5.0, 0.5, 5.0);
		glutSolidCube(1.0);
	glPopMatrix();
	//monitor
	glPushMatrix();
		glTranslatef(6.0, 9.0, -7.5);
		glScalef(6.0, 4.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
    //texturas da tela 
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_monitor);
  	//superfice tela
  	glBegin(GL_QUADS);
  		glColor3f(1.0, 1.0, 1.0);  		
  		glTexCoord2fv(monitortext[0]); glVertex3f(3.5,7.5,-7.2);
  		glTexCoord2fv(monitortext[1]); glVertex3f(8.5,7.5,-7.2);
 		glTexCoord2fv(monitortext[2]); glVertex3f(8.5,10.5,-7.2);
 		glTexCoord2fv(monitortext[3]); glVertex3f(3.5,10.5,-7.1);	
  	glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
  	
  	//costas do monitor
  	//textura do logo
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_unicamp);
  	//superfice costas monitor
  	glBegin(GL_QUADS);	
  		glTexCoord2fv(unicamptext[0]); glVertex3f(3.5,7.5,-7.8);
  		glTexCoord2fv(unicamptext[1]); glVertex3f(8,7.5,-7.8);
 		glTexCoord2fv(unicamptext[2]); glVertex3f(8,10.5,-7.8);
 		glTexCoord2fv(unicamptext[3]); glVertex3f(3.5,10.5,-7.8);	
  	glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
	
	
	//Lampada
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, amarelo_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, amarelo_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, amarelo_brilho);
	glPushMatrix();
		glTranslatef( 0.0, 20.0, 0.0);
		glutSolidSphere(0.5, 10, 8);
	glPopMatrix();
	
	//suporte lampada
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chaleira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chaleira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chaleira_brilho);
	
	glPushMatrix();
		GLUquadricObj *quadric;
		quadric = gluNewQuadric();
	  	gluQuadricTexture(quadric, GL_TRUE);
	  	glTranslatef(0, 20.8, 0.0);
		glRotated(90, 1.0, 0.0, 0.0 );
		glTranslatef(0, 0, 0);
	  	gluCylinder(quadric, 0.2, 1.5, 1, 12, 3);
  	glPopMatrix();
  	
  	//fio lampada  	
	glPushMatrix();
		glTranslatef(0, 21.0, 0);
		glScalef(0.2, 2.5, 0.2);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//maça
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vermelho_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, vermelho_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, vermelho_brilho);
	glPushMatrix();
		//glTranslatef(1.0, 7.3, -3.0); 
		glTranslatef(macaX, macaY, macaZ);
		glutSolidSphere(0.5, 10, 8);
	glPopMatrix();

	//talo da maça
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	glPushMatrix();
		//glTranslatef(1.0, 7.8, -3.0);
		glTranslatef(taloX, taloY, taloZ);
		glScalef(0.2, 0.5, 0.2);
		//glVertex2i(movemaca + 200, 210);
		glutSolidCube(1.0);
	glPopMatrix();

	//objeto Chakeira
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chaleira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chaleira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chaleira_brilho);
	glPushMatrix();
		glTranslatef(12.5, 7.5, -6.0);
		glutSolidTeapot(1.0);
	glPopMatrix();
	
	//copo
	glPushMatrix();
		quadric = gluNewQuadric();
	  	gluQuadricTexture(quadric, GL_TRUE);
	  	glTranslatef(10.5, 7.5, -2.0);
		glRotated(90, 1.0, 0.0, 0.0 );
		glTranslatef(0, 0, 0);
	  	gluCylinder(quadric, 0.5, 0.5, 1, 12, 3);
  	glPopMatrix();
	
	//prateleira
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
	glPushMatrix();
		glTranslatef(-10, 14, -20);
		glScalef(12.0, 0.5, 8);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//Livros em pé
	//livro 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, azul_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, azul_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, azul_brilho);
	glPushMatrix();
		glTranslatef(-8, 17, -18);
		glScalef(1.0, 5, 3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//livro 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	glPushMatrix();
		glTranslatef(-7, 17, -18);
		glScalef(1.0, 5, 3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//livro 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, livro_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	glPushMatrix();
		glTranslatef(-6, 17, -18);
		glScalef(1.0, 5, 3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitados
	//livro deitado 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, azul_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, azul_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, azul_brilho);
	glPushMatrix();
		glTranslatef(-11.5, 15, -18);
		glScalef(5.0, 1, 3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//livro deitado 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	glPushMatrix();
		glTranslatef(-11.5, 16, -18);
		glScalef(5.0, 1, 3);
		glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitado 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vermelho_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	glPushMatrix();
		glTranslatef(-11.5, 17, -18);
		glScalef(5.0, 1, 3);
		glutSolidCube(1.0);
	glPopMatrix();

  
  glPopMatrix();
  glutSwapBuffers();		
}

void carregar_texturas(void)
{
  IMAGE *img;
  GLenum gluerr;

  /* textura do chao */
    glGenTextures(1, &textura_chao);
  	glBindTexture(GL_TEXTURE_2D, textura_chao);
  
  	if(!(img=ImageLoad(TEXTURA_DO_CHAO))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 
 	   /* textura Yuri on Ice */
    glGenTextures(1, &textura_poster);
  	glBindTexture(GL_TEXTURE_2D, textura_poster);
  
  	if(!(img=ImageLoad(TEXTURA_DO_POSTER))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	 
 	 
 	/* textura Haikyuu */
    glGenTextures(1, &textura_haikyuu);
  	glBindTexture(GL_TEXTURE_2D, textura_haikyuu);
  	if(!(img=ImageLoad(TEXTURA_DO_HAIKYUU))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	 
 	 
 	/* textura naruto */
    glGenTextures(1, &textura_naruto);
  	glBindTexture(GL_TEXTURE_2D, textura_naruto);
  	if(!(img=ImageLoad(TEXTURA_NARUTO))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	 
 	 /* textura do monitor - logo ft*/
    glGenTextures(1, &textura_monitor);
  	glBindTexture(GL_TEXTURE_2D, textura_monitor);
  	if(!(img=ImageLoad(TEXTURA_DO_MONITOR))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	  	 
 	/* textura costas do monitor - logo unicamp*/
    glGenTextures(1, &textura_unicamp);
  	glBindTexture(GL_TEXTURE_2D, textura_unicamp);
  	if(!(img=ImageLoad(TEXTURA_UNICAMP))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	
 	  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	 
 	/* textura do cobertor*/
    glGenTextures(1, &textura_cobertor);
  	glBindTexture(GL_TEXTURE_2D, textura_cobertor);
  	if(!(img=ImageLoad(TEXTURA_COBERTOR))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	  	 
 	 /* textura porta*/
    glGenTextures(1, &textura_porta);
  	glBindTexture(GL_TEXTURE_2D, textura_porta);
  	if(!(img=ImageLoad(TEXTURA_PORTA))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	    
 	    
 	/* textura evangelion*/
    glGenTextures(1, &textura_evangelion);
  	glBindTexture(GL_TEXTURE_2D, textura_evangelion);
  	if(!(img=ImageLoad(TEXTURA_EVANGELION))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
 	    
 	     	/* textura kimetsu*/
    glGenTextures(1, &textura_kimetsu);
  	glBindTexture(GL_TEXTURE_2D, textura_kimetsu);
  	if(!(img=ImageLoad(TEXTURA_KIMETSU))) {
    	fprintf(stderr,"Error reading a texture.\n");
    	exit(-1);
  	}
  	gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  	if(gluerr){
 	   fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
 	   exit(-1);
 	}
 	  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
}

void reshape (int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(55.0, (GLfloat) w/(GLfloat) h, 1.0, 60.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, -8.0, -30.0);
  
}

void keyboard(unsigned char key, int x, int y)
{
  switch (key) {
 case 'r':
    rodatudo = (rodatudo + 5) % 360;
    glutPostRedisplay();
    break;
  case 'R':
    rodatudo = (rodatudo - 5) % 360;
    glutPostRedisplay();
    break;
  case 'O':
    PASSOS = 0;
    break;    

   case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

void maca(int passo)
{
	if(PASSOS == 0){
		//printf("Primeira passada \n");

		//valores iniciais da maça
		macaX = 1.0;
		macaY =  7.5;
		macaZ = -3.0;
		
		taloX = 1.0;
		taloY = macaY + 0.5;
		taloZ = -3.0;
	}
	else {
		if(PASSOS % 25 == 0 && PASSOS <=850)
		{
			//roda a tela
			rodatudo = (rodatudo + 5) % 360;
   			glutPostRedisplay();
		}
		if(PASSOS % 10 == 0 && macaX >= -0.5){ //move maça x
			macaX = macaX - 0.1;	
			taloX = macaX - 0.1;
		}
		else {
			if (PASSOS % 10 == 0 && macaY >= 1) // move maça y
			{
				macaY = macaY -0.1;	
				taloY = macaY + 0.5;	
			}		
		}
	}
	PASSOS++;
	glutPostRedisplay();
	glutTimerFunc(10, maca, 1);

}


void init(void)
{
  glClearColor (1.0f, 0.5f, 1.0f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  carregar_texturas();
 
  gouraud=1;
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

  glLightfv(GL_LIGHT0, GL_DIFFUSE, cor_luz);
  glLightfv(GL_LIGHT0, GL_SPECULAR, cor_luz);
  glLightfv(GL_LIGHT0, GL_AMBIENT, cor_luz_amb);
  glLightfv(GL_LIGHT0, GL_POSITION, posicao_luz);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glEnable(GL_AUTO_NORMAL);
  glEnable(GL_NORMALIZE);
  
}


int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (800, 800); 
  glutInitWindowPosition (0, 0);
  glutCreateWindow ("Quarto de um otaku");
  
  init ();
  
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  
  glutTimerFunc(10, maca, 1);
  
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  
  return 0;
}



