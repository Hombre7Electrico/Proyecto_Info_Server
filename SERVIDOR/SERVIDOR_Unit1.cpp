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
int MAXpHa=0;
int minpHa=0;
float randpHa=0;
//temp_jsimple
int MAXtempjs=0;
int mintempjs=0;
float randtempjs=0;
//temp_jterminado
int MAXtempjt=0;
int mintempjt=0;
float randtempjt=0;
//presion_tanqueC
int MAXprest=0;
int minprest=0;
float randprest=0;
//pH_gaseos
int MAXpHg=0;
int minpHg=0;
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
//Tomo los valores de los edit
//pHagua
MAXpHa=atoi(Edit2->Text.c_str());
minpHa=atoi(Edit1->Text.c_str());

//temp_jsimple
MAXtempjs=atoi(Edit4->Text.c_str());
mintempjs=atoi(Edit3->Text.c_str());
//temp_jterminado
MAXtempjt=atoi(Edit6->Text.c_str());
mintempjt=atoi(Edit5->Text.c_str());
//presion_tanqueC
MAXprest=atoi(Edit8->Text.c_str());
minprest=atoi(Edit7->Text.c_str());
//pH_gaseos
MAXpHg=atoi(Edit10->Text.c_str());
minpHg=atoi(Edit9->Text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  //INCREMENTO LA VARIABLE pH del agua
  //ACTUALIZO LA INTERFAZ
  randpHa=minpHa+random(MAXpHa-minpHa)+1-random(10)*0.1;
  //random(10)*0.1 a lo suma entrega 1, -1 elimina el posible desborde
  Label1->Caption= FloatToStrF(randpHa,ffNumber,20,2);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem1->Text = Label1->Caption;

  //HABILITO EL TIMER 2 PARA CONTINUAR LA SECUENCIA
  Timer2->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 //APAGO EL TIMER 2
  Timer2->Enabled=false;

  //INCREMENTO LA VARIABLE temperatura jarabe
  //ACTUALIZO LA INTERFAZ
  randtempjs=mintempjs+random(MAXtempjs-mintempjs)+1-random(10)*0.1;
  //random(10)*0.1 a lo suma entrega 1, -1 elimina el posible desborde
  Label2->Caption = FloatToStrF(randtempjs,ffNumber,20,2);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem2->Text = Label2->Caption;

  //HABILITO EL TIMER 3 PARA CONTINUAR LA SECUENCIA
  Timer3->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
 //APAGO EL TIMER 3
  Timer3->Enabled=false;

  //INCREMENTO LA VARIABLE TEMPERATURA
  //ACTUALIZO LA INTERFAZ
  randtempjt=mintempjt+random(MAXtempjt-mintempjt)+1-random(10)*0.1;
  //random(10)*0.1 a lo suma entrega 1, -1 elimina el posible desborde
  Label3->Caption = FloatToStrF(randtempjt,ffNumber,20,2);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem3->Text = Label3->Caption;

  //HABILITO EL TIMER 3 PARA CONTINUAR LA SECUENCIA
  Timer4->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer4Timer(TObject *Sender)
{
 //APAGO EL TIMER 4
  Timer4->Enabled=false;

  //INCREMENTO LA VARIABLE presion tanque
  //ACTUALIZO LA INTERFAZ
  randprest=minprest+random(MAXprest-minprest)+1-random(10)*0.1;
  //random(10)*0.1 a lo suma entrega 1, -1 elimina el posible desborde
  Label4->Caption = FloatToStrF(randprest,ffNumber,20,2);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem4->Text = Label4->Caption;

  //HABILITO EL TIMER 5 PARA CONTINUAR LA SECUENCIA
  Timer5->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer5Timer(TObject *Sender)
{
//APAGO EL TIMER 5
  Timer5->Enabled=false;

  //INCREMENTO LA VARIABLE TEMPERATURA
  //ACTUALIZO LA INTERFAZ
  randpHg=minpHg+random(MAXpHg-minpHg)+1-random(10)*0.1;
  //random(10)*0.1 a lo suma entrega 1, -1 elimina el posible desborde
  Label5->Caption = FloatToStrF(randpHg,ffNumber,20,2);

  //ACTUALIZO EL VALOR EN EL ITEM
  DdeServerItem5->Text = Label5->Caption;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
minpHa=atoi(Edit1->Text.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
MAXpHa=atoi(Edit2->Text.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
mintempjs=atoi(Edit3->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
MAXtempjs=atoi(Edit4->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5Change(TObject *Sender)
{
mintempjt=atoi(Edit5->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Change(TObject *Sender)
{
MAXtempjt=atoi(Edit6->Text.c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Change(TObject *Sender)
{
minprest=atoi(Edit7->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8Change(TObject *Sender)
{
MAXprest=atoi(Edit8->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit9Change(TObject *Sender)
{
minpHg=atoi(Edit9->Text.c_str());        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit10Change(TObject *Sender)
{
MAXpHg=atoi(Edit10->Text.c_str());
}
//---------------------------------------------------------------------------

