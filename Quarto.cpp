 //Prof. Marco Antonio, abr/2020, ST765 FT UNICAMP
// Programa baseado no exercício "Parquinho.c" e "Jato.c"
// Aplicação de texturas
// Clara Anna Miranda - 155041
// Katherine Rocha - 106768
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "image.h"


#define TEXTURA_DO_POSTER "img/poster.rgb"
#define TEXTURA_DO_HAIKYUU "img/haikyuu.rgb"
#define TEXTURA_NARUTO "img/naruto.rgb"

#define TEXTURA_COBERTOR "img/cobertor.rgb"
#define TEXTURA_PORTA "img/door.rgb"

#define TEXTURA_DO_CHAO "img/piso.rgb"
#define TEXTURA_MADEIRA "img/madeira.rgb"
#define TEXTURA_DO_MONITOR "img/logo_ft.rgb"
#define TEXTURA_UNICAMP "img/unicamp.rgb"

#define PI 3.1415
GLfloat tetaxz = 0;
GLfloat raioxz = 6;
GLfloat obs[3] = { 0.0,7.0,0.0 };
GLfloat look[3] = { 0.0,3.0,0.0 };



//var textura
GLuint  textura_chao;
GLuint  textura_cobertor;
GLuint  textura_porta;


GLuint  textura_poster;
GLuint  textura_haikyuu;
GLuint  textura_naruto;

GLuint  textura_monitor;
GLuint  textura_unicamp;


//var mudanca perspectiva
static int rodatudo = 0;

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


//moldura poster naruto 
GLfloat naruto_difusa[]    = { 0.0, 0.2, 0.3, 1.0 };
GLfloat naruto_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat naruto_brilho[]    = { 60.0 };

//moldura poster haikyuu 
GLfloat haikyuu_difusa[]    = {0.7, 0.3, 0.0, 1.0 };
GLfloat haikyuu_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat haikyuu_brilho[]    = { 60.0 };

//moldura poster YoI 
GLfloat yoi_difusa[]    = { 0.4, 0.4, 1.0, 1.0 };
GLfloat yoi_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat yoi_brilho[]    = { 60.0 };


GLfloat madeira_difusa[]    = { 0.5, 0.0, 0.0, 1.0 };
GLfloat madeira_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat madeira_brilho[]    = { 30.0 };

GLfloat computador_difusa[]    = { 0.0, 0.0, 0.0, 1.0 };
GLfloat computador_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat computador_brilho[]    = { 50.0 };


GLfloat vermelho_difusa[]    = { 1.0, 0.0, 0.0, 1.0 };
GLfloat vermelho_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat vermelho_brilho[]    = { 50.0 };


GLfloat chaleira_difusa[]    = { 0.5, 0.5, 0.5, 1.0 };
GLfloat chaleira_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chaleira_brilho[]    = { 50.0 };

GLfloat verde_difusa[]    = { 0.0, 1.0, 0.0, 1.0 };
GLfloat verde_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat verde_brilho[]    = { 40.0 };

GLfloat azul_difusa[]    = { 0.0, 0.2, 0.5, 1.0 };
GLfloat azul_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat azul_brilho[]    = { 40.0 };

GLfloat branco_difusa[]    = { 0.0, 0.5, 0.8, 1.0 };
GLfloat branco_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat branco_brilho[]    = { 15.0 };

GLfloat amarelo_difusa[]    = { 0.5, 0.5, 0.0, 1.0 };
GLfloat amarelo_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat amarelo_brilho[]    = { 35.0 };

//acrescentar aqui opções de cores pros livros diferentes
GLfloat livro_difusa[]    = { 0.6, 0.5, 0.0, 1.0 };  //
GLfloat livro_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat livro_brilho[]    = { 40.0 };

GLfloat chao_difusa[]    = { 1.0, 0.0, 1.0, 1.0 };
GLfloat chao_especular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat chao_brilho[]    = { 50.0 };

GLfloat posicao_luz[]    = { 0.0, 20.0, 0.0, 1.0};
GLfloat cor_luz[]        = { 1.0, 1.0, 1.0, 1.0};
GLfloat cor_luz_amb[]    = { 0.3, 0.3, 0.3, 1.0};

GLint gouraud=0;


void display(void){

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
	
	//iluminação do chao
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chao_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chao_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chao_brilho);
  	
	//Textura do chao
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_chao);
  	glEnable(GL_TEXTURE_2D);  //seta textura
	  glBegin(GL_QUADS);
	  	glColor3f(0.5, 0.8, 0.0);
	  	glTexCoord2fv(planotext[0]); glVertex3f(-20,0.5,20);
	  	glTexCoord2fv(planotext[1]); glVertex3f(20,0.5,20);
	  	glTexCoord2fv(planotext[2]); glVertex3f(20,0.5,-20);
	  	glTexCoord2fv(planotext[3]); glVertex3f(-20,0.5,-20);
	  glEnd();
  glDisable(GL_TEXTURE_2D); //encerra textura
  

  	//Quadro 1: Yuri on Ice
  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, yoi_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, yoi_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, yoi_brilho);
  	
  		//moldura 
  		glColor3f(0.5, 0.5, 0.8);
		glPushMatrix();
			glTranslatef(13.5,15, -20.3);
			glScalef(15,12, 0.5);
			glutSolidCube(1.0);
		glPopMatrix();
  
  	//textura do poster uoi
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_poster);
  	//superfice poster yoi
	    glBegin(GL_QUADS);
	    	glColor3f(0.5, 0.0, 0.0);
	  		glTexCoord2fv(postertext[0]);  glVertex3f(7.5,10,-20);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(20,10,-20);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(20,20,-20);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(7.5,20,-20);
		glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura
  	
  	//Poster 2: Haikyuu
  	  	//iluminacao
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, haikyuu_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, haikyuu_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, haikyuu_brilho);
  	
  	  	//moldura poster haikyuu
  		glColor3f(0.8, 0.5, 0.0);
		glPushMatrix();
			glTranslatef(-10,15, 20.3);
			glScalef(15,12, 0.5);
			glutSolidCube(1.0);
		glPopMatrix();
  
  		//textura do poster haikyuu
  		glEnable(GL_TEXTURE_2D);  //seta textura
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  		glBindTexture(GL_TEXTURE_2D,textura_haikyuu);
  		
		//superfice poster haikyuu
	    glBegin(GL_QUADS);
	    	glColor3f(0.5, 0.0, 0.0);
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
	    	glColor3f(0.5, 0.0, 0.0);
	  		glTexCoord2fv(postertext[0]);  glVertex3f(2.8,10,20);
	  		glTexCoord2fv(postertext[1]);  glVertex3f(17,10,20);
	 	 	glTexCoord2fv(postertext[2]);  glVertex3f(17,20,20);
	 	 	glTexCoord2fv(postertext[3]);  glVertex3f(2.8,20,20);
		glEnd();
  	glDisable(GL_TEXTURE_2D); //encerra textura*/

  	
  	//cama
  	
  	  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, branco_difusa);
  		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, branco_especular);
  		glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, branco_brilho);
			//base
			glPushMatrix();
				glTranslatef(-10, 2.4, 15.0);
				glScalef(20, 3, 10.0);
				glutSolidCube(1.0);
			glPopMatrix();
			
			//travesseiro
			/*glPushMatrix();
				glTranslatef(-17, 4.5, 15.0);
				glScalef(5, 1.5, 5);
				glutSolidCube(1.0);
			glPopMatrix();*/
			
			//cobertor
			//textura pcobertor
		  	glEnable(GL_TEXTURE_2D);  //seta textura
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
		  	glBindTexture(GL_TEXTURE_2D,textura_cobertor);
	
	  //superfice cobertor
	    glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,4,10);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,4,10);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,20);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,20);
		glEnd();
		
		glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,0,9.9);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,0,9.9);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,9.9);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,9.9);
		glEnd();
		
				glBegin(GL_QUADS);
			glTexCoord2fv(cobertortext[0]);  glVertex3f(0,0,20.1);
	  		glTexCoord2fv(cobertortext[1]);  glVertex3f(-17,0,20.1);
	 	 	glTexCoord2fv(cobertortext[2]);  glVertex3f(-17,4,20.1);
	 	 	glTexCoord2fv(cobertortext[3]);  glVertex3f(0,4,20.1);
		glEnd();
		
  	glDisable(GL_TEXTURE_2D); //encerra textura*/
  	
  	
  	//porta
  	  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_porta);
  	
  	  	glBegin(GL_QUADS);
			glTexCoord2fv(portatext[0]);glVertex3f(-20,15,0);
	  		glTexCoord2fv(portatext[1]);glVertex3f(-20,0,0);
	 	 	glTexCoord2fv(portatext[2]);glVertex3f(-20,0,-10);
	 	 	glTexCoord2fv(portatext[3]);glVertex3f(-20,15,-10);
		glEnd();
				
				glDisable(GL_TEXTURE_2D); //encerra textura*/
			
			
			
			
		
  	
  	
	 //cadeira
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
	 
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, 5.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, 5.0, 0.0);
	glScalef(0.5, 8.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	//encosto
	//ilumiacao cadeira	 
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
  	
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, 7.0, 0.0);
	glScalef(4.0, 4.0, 0.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//assento
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.0, 4.0, -2.0);
	glScalef(5.0, 0.5, 4.0);
	glutSolidCube(1.0);
	glPopMatrix();

	//pernas
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(5.0, 2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(9.0, 2.5, -3.5);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//iluminacao mesa
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, madeira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, madeira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, madeira_brilho);
	
	//mesa
	//tampo
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(7.5, 6.5, -5.0);
	glScalef(15.0, 0.5, 8.0);
	glutSolidCube(1.0);
	glPopMatrix();


	//pernas da mesa
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, 3.5, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, 3.5, -2.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(14.5, 3.5, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(0.5, 3.5, -8.0);
	glScalef(0.5, 6.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//computador
	//base
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, computador_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, computador_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, computador_brilho);
	
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(6.0, 7.0, -5.0);
	glScalef(5.0, 0.5, 5.0);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	//monitor
	glColor3f(0.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(6.0, 9.0, -7.5);
	glScalef(6.0, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
  
    //textura da tela 
  	glEnable(GL_TEXTURE_2D);  //seta textura
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  	glBindTexture(GL_TEXTURE_2D,textura_monitor);
  	
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
  	
  	glBegin(GL_QUADS);
  		glColor3f(0.0, 0.0, 0.0);  		
  		glTexCoord2fv(unicamptext[0]); glVertex3f(3.5,7.5,-7.8);
  		glTexCoord2fv(unicamptext[1]); glVertex3f(8,7.5,-7.8);
 		glTexCoord2fv(unicamptext[2]); glVertex3f(8,10.5,-7.8);
 		glTexCoord2fv(unicamptext[3]); glVertex3f(3.5,10.5,-7.8);	
  	glEnd();
  	
  	glDisable(GL_TEXTURE_2D); //encerra textura
	
	
	
	//lampada
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
  	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chaleira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chaleira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chaleira_brilho);
  	
	glPushMatrix();
	glTranslatef(0, 21.0, 0);
	glScalef(0.3, 2.5, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	

	//maça
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vermelho_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, vermelho_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, vermelho_brilho);
	
	glColor3f(6,0.0,0);
	glPushMatrix();
	glTranslatef(1.0, 7.3, -3.0);
	glutSolidSphere(0.5, 10, 8);
	glPopMatrix();

	//cabo Maça
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	
	glColor3f(0.0, 0.5, 0.0);
	glPushMatrix();
	glTranslatef(1.0, 7.8, -3.0);
	glScalef(0.2, 0.5, 0.2);
	glutSolidCube(1.0);
	glPopMatrix();


	//objeto Chakeira
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chaleira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chaleira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chaleira_brilho);
	
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(12.5, 7.5, -6.0);
	glutSolidTeapot(1.0);
	glPopMatrix();
	
	
	//copo
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, chaleira_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, chaleira_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, chaleira_brilho);
	
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	//GLUquadricObj *quadric;
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
	
	glColor3f(0.5, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-10, 14, -20);
	glScalef(12.0, 0.5, 8);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	//livro 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, azul_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, azul_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, azul_brilho);
	
	glColor3f(1.0, 0.2, 0.0);
	glPushMatrix();
	glTranslatef(-8, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	
	//livro 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	
	glColor3f(0.0, 1.0, 0.5);
	glPushMatrix();
	glTranslatef(-7, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	

	//livro 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, livro_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	
	glColor3f(0.0, 0.5, 1);
	glPushMatrix();
	glTranslatef(-6, 17, -18);
	glScalef(1.0, 5, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitados 1
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, azul_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, azul_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, azul_brilho);
	
	glColor3f(0.5, 0.0, 1);
	glPushMatrix();
	glTranslatef(-11.5, 15, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitados 2
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, verde_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, verde_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, verde_brilho);
	
	glColor3f(1.0, 0.2, 0.2);
	glPushMatrix();
	glTranslatef(-11.5, 16, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	//livros deitados 3
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, vermelho_difusa);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, livro_especular);
  	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, livro_brilho);
	
	glColor3f(0.5, 1.0, 0.2);
	glPushMatrix();
	glTranslatef(-11.5, 17, -18);
	glScalef(5.0, 1, 3);
	glutSolidCube(1.0);
	glPopMatrix();
	
	

  glPopMatrix();
  glutSwapBuffers();
}

void carregar_texturas(void){
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
 /*	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
 	 glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
 	 glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);*/
 	 
 	 
 	   /* textura do poster */
  
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
 	 
 	 
 	 	   /* textura do poster */
  
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
 	 
 	 
 	  	 	   /* textura do poster */
  
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
 	 
 	 
 	 
 	 
 	  	   /* textura do monitor */
  
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
 	 
 	 
 	 
 	  	 
 	  	   /* textura do monitor unicamp*/
  
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
  
  
  
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(55.0, (GLfloat) w/(GLfloat) h, 1.0, 60.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, -8.0, -30.0);
  
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
 case 'r':
    rodatudo = (rodatudo + 5) % 360;
    glutPostRedisplay();
    break;
  case 'R':
    rodatudo = (rodatudo - 5) % 360;
    glutPostRedisplay();
    break;/*
case 'T':
		rodatudo = (rodatudo + 5) % 360;
		glutPostRedisplay();
		break;
	case 't':
		rodatudo = (rodatudo - 5) % 360;
		glutPostRedisplay();*/
		break;
   case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

void init(void){
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


int main(int argc, char** argv){
  glutInit(&argc, argv);
  //glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}



