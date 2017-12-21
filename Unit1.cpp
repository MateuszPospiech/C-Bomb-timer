//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <mmsystem.h>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int pozostalo=10;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
pozostalo--;
int godzina, minuta, sekunda;
AnsiString godz, min, sek;

godzina = pozostalo / 3600;
godz = IntToStr(godzina);
if (godzina<10) godz="0"+godz;

minuta = (pozostalo - godzina*3600) /60;
min = IntToStr(minuta);
if (minuta<10) min="0"+min;

sekunda = pozostalo - godzina*3600 - minuta*60;
sek = IntToStr(sekunda);
if (sekunda<10) sek="0"+sek;

Label1->Caption = godz+":"+min+":"+sek;
sndPlaySound("sound\\paka.wav", SND_ASYNC);


if (sekunda<=0)
{
paka->Visible=false;
Label1->Visible=false;
Timer1-> Enabled = false;
Image1->Visible=true;
sndPlaySound("sound\\Akbar.wav", SND_ASYNC);
}





}
//---------------------------------------------------------------------------
