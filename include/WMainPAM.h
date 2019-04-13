///////////////////////////////////////////////////////////////////////////
//                                                                       //
// NOTICE OF COPYRIGHT                                                   //
//                                                                       //
//                       Copyright (C) 2019                              //
//                Arnold Alonso¹  - Julian Salamanca²                    //
//                                                                       //
//                aralonsoa@correo.udistrital.edu.co¹                    //
//                   jasalamanca@udistrital.edu.co²                      //
//                                                                       //
//       ¹²Grupo de Física e Informática (FISINFOR) Universidad          //
//                  Distrital Francisco José de Caldas                   //
//                                                                       //
//                                                                       //
//                 https://github.com/fisinforgh/CHAOS                   //
//                                                                       //
// This program is free software; you can redistribute it and/or modify  //
// it under the terms of the GNU General Public License as published by  //
// the Free Software Foundation; either version 2 of the License, or     //
// (at your option) any later version.                                   //
//                                                                       //
// This program is distributed in the hope that it will be useful,       //
// but WITHOUT ANY WARRANTY; without even the implied warranty of        //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
// GNU General Public License for more details:                          //
//                                                                       //
//               http://www.gnu.org/copyleft/gpl.html                    //
//                                                                       //
///////////////////////////////////////////////////////////////////////////

#ifndef _CHAOS_WMainPAM
#define _CHAOS_WMainPAM

#include "TRootEmbeddedCanvas.h"
#include "TGButtonGroup.h"
#include "TGNumberEntry.h"
#include "TApplication.h"
#include "TRootCanvas.h"
#include "TGTextEntry.h"
#include "TGComboBox.h"
#include "TCurlyLine.h"
#include "RQ_OBJECT.h"
#include "TGClient.h"
#include "TG3DLine.h"
#include "TGLayout.h"
#include "TGClient.h"
#include "TGWindow.h"
#include "TGButton.h"
#include "TGraph2D.h"
#include "TGFrame.h"
#include "TGLabel.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TImage.h"
#include "TText.h"
#include "TGTab.h"

#include <ctime>

#include "TMatrixDUtils.h"
#include "TMatrixDEigen.h"
#include "TMultiGraph.h"
#include "Riostream.h"
#include "TEllipse.h"
#include "TMatrixD.h"
#include "TVectorD.h"
#include "TArrayD.h"
#include "TGraph.h"
#include "TArrow.h"
#include "TTimer.h"
#include "TMath.h"
#include "TLine.h"
#include "TAxis.h"
#include "TBox.h"

using namespace std;

class WMainPAM{
  RQ_OBJECT("WMainPAM");
 private:
  TRootEmbeddedCanvas *EmbeddedSimulCanvas, *EmbeddedFaseCanvas, *EmbeddedPoinCanvas;
  TRootEmbeddedCanvas *EmbeddedLyapuCanvas;
  TGHorizontalFrame   *HFrame1, *HFrame115, *HFrame1111, *HFrame1112, *HFrame1121, *HFrame1131, *HFrame1132;
  TGHorizontalFrame   *HFrame11321, *HFrame11322, *HFrame1141, *HFrame1142, *HFrame11421, *HFrame11422;
  TGCompositeFrame    *CompFrame121, *CompFrame122, *CompFrame123, *CompFrame124;
  TGVerticalFrame     *VFrame11, *VFrame12;
  TGNumberEntry       *NumEntMass, *NumEntLength, *NumEntRadius, *NumEntRho, *NumEntC, *NumEntG;
  TGNumberEntry       *NumEntF, *NumEntOmega_F, *NumEntOmega, *NumEntTheta, *NumEntZ;
  TGCheckButton       *CheckButtonVectors;
  TGGroupFrame        *GroupPenPro, *GroupMedPro, *GroupSimPar, *GroupIniCon;
  TGTextButton        *TextButtonCalculate, *TextButtonPlay,*TextButtonClear, *TextButtonExit;
  TGMainFrame         *MainFrame;
  TGLabel             *LabelMass, *LabelLength, * LabelRadius, *LabelRho, *LabelC, *LabelG;
  TGLabel             *LabelF, *LabelOmega_F, *LabelOmega, *LabelTheta, *LabelZ;
  TCanvas             *CanvasSimul, *CanvasFase, *CanvasPoin, *CanvasLyapu;  
  TGTab               *Tabs;
  TBox                *Box;

  TMultiGraph      *Exponentes;
  TEllipse         *Lentil;
  TArrow           *ArrowPush, *ArrowDrag, *ArrowWeight, *ArrowForcing;
  TGraph           *TGraphPhase, *TGraphPoincare, *TGraphLyapunov, *TGraphL1, *TGraphL2, *TGraphL3;
  TTimer           *Cont;
  TLine            *Rope;
  Int_t            IsActive;
  
  ofstream outfile;
  ifstream infile;
  
  Double_t Omega_Matrix[200]={0.0};
  Double_t Theta_Matrix[200]={0.0};
  Double_t Omega_M_Poin[1000]={0.0};
  Double_t Theta_M_Poin[1000]={0.0};
  
  Double_t SeigenvalOmega;
  Double_t SeigenvalTheta;
  Double_t SeigenvalZ;

  Double_t MeigenvalOmega;
  Double_t MeigenvalTheta;
  Double_t MeigenvalZ;
  
  Double_t T[200]      = {0.};
  Double_t LOmega[200] = {0.};
  Double_t LTheta[200] = {0.};
  Double_t LZ[200]     = {0.};
  
  Double_t Omega_F = 0.;
  Double_t Omega   = 0.;
  Double_t Theta   = 0.;
  Double_t Alpha   = 0.;
  Double_t Gamma   = 0.;
  Double_t Beta    = 0.;
  Double_t Time    = 0.;
  Double_t Rho     = 0.;
  Double_t C       = 0.;
  Double_t F       = 0.;
  Double_t I       = 0.;
  Double_t R       = 0.;
  Double_t M       = 0.;
  Double_t L       = 0.;
  Double_t G       = 0.;
  Double_t Z       = 0.;
  Int_t    i       = 0;
  Int_t    j       = 0;
  Int_t    k       = 0;
  Int_t    n       = 0;
  
  //unsigned t0, t1;

  void Disable();
  void Enable();
  
 public:
  WMainPAM(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options);
  virtual ~WMainPAM();  
  
  Double_t GetOmega_F(){return NumEntOmega_F -> GetNumber();}
  Double_t GetLength(){return NumEntLength -> GetNumber();}
  Double_t GetRadius(){return NumEntRadius -> GetNumber();}
  Double_t GetTheta(){return NumEntTheta -> GetNumber();}
  Double_t GetOmega(){return NumEntOmega -> GetNumber();}
  Double_t GetMass(){return NumEntMass -> GetNumber();}
  Double_t GetRho(){return NumEntRho -> GetNumber();}
  Double_t GetC(){return NumEntC -> GetNumber();}
  Double_t GetG(){return NumEntG -> GetNumber();}
  Double_t GetF(){return NumEntF -> GetNumber();}
  Double_t GetZ(){return NumEntZ -> GetNumber();}


  void TBCalculateSimulCliked();
  void DrawBeforeVectors();
  void ResizeSimulCanvas();
  void TBClearCliked();
  void TBPlayCliked();
  void TBExitCliked();
  void DrawSystem();
  void DoDraw();
  
  ClassDef(WMainPAM, 0);
};

#endif
//#ifdef __CINT__
//#include "../src/WMainPAM.cxx"
//#endif

//__________________________________________________________________________________________________________
//
//EOF
//
