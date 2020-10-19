//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SERVIDOR_Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//variables servidor
int pH_agua=0, temp_jsimple=0, temp_jterminado=0, presion_tanqueC=0, pH_gaseosa=0;

//pHagua
int MAXpHa=0,minpHa=0;
float randpHa=0;
//temp_jsimple
int MAXtempjs=0,mintempjs=0;
float randtempjs=0;
//temp_jterminado
int MAXtempjt=0,mintempjt=0;
float randtempjt=0;
//presion_tanqueC
int MAXprest=0,minprest=0;
float randprest=0;
//pH_gaseosa
int MAXpHg=0,minpHg=0;
float randpHg=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//TIMERS APAGADOS PARA CONFIGURARLOS
Timer1->Enabled = false;
Timer2->Enabled = false;
Timer3->Enabled = false;
Timer4->Enabled = false;
Timer5->Enabled = false;
//CONFIGURACIÓN DE LOS INTERVALOS DE LOS TIMERS
Timer1->Interval = 1000;
Timer2->Interval = 200;
Timer3->Interval = 200;
Timer4->Interval = 200;
Timer5->Interval = 200;
//CONFIGURACIÓN DE LOS ITEMS
DdeServerItem1->ServerConv = DdeServerConv1;
DdeServerItem2->ServerConv = DdeServerConv1;
DdeServerItem3->ServerConv = DdeServerConv1;
DdeServerItem4->ServerConv = DdeServerConv1;
DdeServerItem5->ServerConv = DdeServerConv1;
// ARRANQUE DE LA SECUENCIA
Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
MAXpHa=8;
minpHa=5;
  //INCREMENTO LA VARIABLE pH del agua
  //ACTUALIZO LA INTERFAZ
  randpHa=minpHa+random(MAXpHa-minpHa+27)*0.1;   //el ph va a ser de agua siempre
  Label1->Caption= FloatToStr(randpHa);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem1->Text = Label1->Caption;

  //HABILITO EL TIMER 2 PARA CONTINUAR LA SECUENCIA
  Timer2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
MAXtempjs=80;
mintempjs=90;

 //APAGO EL TIMER 2
  Timer2->Enabled=false;

  //INCREMENTO LA VARIABLE temperatura jarabe
  //ACTUALIZO LA INTERFAZ
  randtempjs=mintempjs+random(MAXtempjs-mintempjs+90)*0.1;
  Label2->Caption = FloatToStr(randtempjs);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem2->Text = Label2->Caption;

  //HABILITO EL TIMER 3 PARA CONTINUAR LA SECUENCIA
  Timer3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
MAXtempjt=10;
mintempjt=3;

 //APAGO EL TIMER 3
  Timer3->Enabled=false;

  //INCREMENTO LA VARIABLE TEMPERATURA
  //ACTUALIZO LA INTERFAZ
  randtempjt=mintempjt+random(MAXtempjt-mintempjt+27)*0.1;
  Label3->Caption = FloatToStr(randtempjt);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem3->Text = Label3->Caption;

  //HABILITO EL TIMER 3 PARA CONTINUAR LA SECUENCIA
  Timer4->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
MAXprest=500;
minprest=350;

 //APAGO EL TIMER 4
  Timer4->Enabled=false;

  //INCREMENTO LA VARIABLE presion tanque
  //ACTUALIZO LA INTERFAZ
  randprest=minprest+random(MAXprest-minprest+1350)*0.1;
  Label4->Caption = FloatToStr(randprest);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem4->Text = Label4->Caption;

  //HABILITO EL TIMER 5 PARA CONTINUAR LA SECUENCIA
  Timer5->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
MAXpHg=6;
minpHg=4;

 //APAGO EL TIMER 5
  Timer5->Enabled=false;

  //INCREMENTO LA VARIABLE TEMPERATURA
  //ACTUALIZO LA INTERFAZ
  randpHg=minpHg+random(MAXpHg-minpHg+20)*0.1;
  Label5->Caption = FloatToStr(randpHg);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem5->Text = Label5->Caption;
}
//---------------------------------------------------------------------------
