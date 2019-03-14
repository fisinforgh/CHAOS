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

#ifndef _CHAOS_WMainPE
#define _CHAOS_WMainPE

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

class WMainPE{
  RQ_OBJECT("WMainPE");
 private:
  TRootEmbeddedCanvas *EmbeddedSimulCanvas, *EmbeddedFaseRCanvas, *EmbeddedFaseACanvas, *EmbeddedLyapuCanvas;
  TGHorizontalFrame   *HFrame1, *HFrame1111, *HFrame1112, *HFrame1121, *HFrame11211, *HFrame11212;
  TGHorizontalFrame   *HFrame1122, *HFrame1131, *HFrame1132, *HFrame114;
  TGCompositeFrame    *CompFrame1311, *CompFrame1312, *CompFrame1313;
  TGVerticalFrame     *VFrame11, *VFrame12, *VFrame13;
  TGNumberEntry       *NumEntMass, *NumEntK, *NumEntLength, *NumEntG, *NumEntTheta, *NumEntOmega;
  TGNumberEntry       *NumEntR, *NumEntV;
  TGCheckButton       *CheckButtonVectors;
  TGGroupFrame        *GroupPenPro, *GroupSimPar, *GroupIniCon;
  TGTextButton        *TextButtonCalculate, *TextButtonPlay, *TextButtonClear, *TextButtonExit;
  TGMainFrame         *MainFrame;
  TGLabel             *LabelMass, *LabelK, *LabelLength, *LabelG, *LabelTheta, *LabelOmega;
  TGLabel             *LabelR, *LabelV;
  TCanvas             *CanvasSimul, *CanvasFaseR, *CanvasFaseA, *CanvasLyapu;  
  TGTab               *Tabs;
  TBox                *Box;
  
  TEllipse            *Lentil;
  TArrow              *ArrowWeight, *ArrowStress;
  TMultiGraph         *Exponentes;
  TGraph              *TGraphPhaseR, *TGraphPhaseA, *TGraphL1, *TGraphL2, *TGraphL3, *TGraphL4;
  TTimer              *Cont;
  TCurlyLine          *Spring;
  Int_t               IsActive;
  
  ofstream outfile;
  ifstream infile;
  
  Double_t Omega_Matrix[200]  = {0.};
  Double_t Theta_Matrix[200]  = {0.};
  Double_t Radial_Matrix[200] = {0.};
  Double_t Speed_Matrix[200]  = {0.};
  
  Double_t SeigenvalP     = 0.;
  Double_t SeigenvalRho   = 0.;
  Double_t SeigenvalL     = 0.;
  Double_t SeigenvalTheta = 0.;

  Double_t MeigenvalP     = 0.;
  Double_t MeigenvalRho   = 0.;
  Double_t MeigenvalL     = 0.;
  Double_t MeigenvalTheta = 0.;

  Double_t T[200]      = {0.};
  Double_t LP[200]     = {0.};
  Double_t LRho[200]   = {0.};
  Double_t LL[200]     = {0.};
  Double_t LTheta[200] = {0.};
  
  Double_t Discriminant = 0.;
  Double_t Rho_1        = 0.;
  Double_t Rho_2        = 0.;
  Double_t Omega        = 0.;
  Double_t Theta        = 0.;
  Double_t Speed        = 0.;
  Double_t P            = 0.;
  Double_t L            = 0.;
  Double_t Rho          = 0.;
  Double_t Time         = 0.;
  Double_t Mass         = 0.;
  Double_t K            = 0.;
  Double_t Length       = 0.;
  Double_t G            = 0.;
  Double_t H            = 0.;
  Int_t    k            = 0;
  Int_t    j            = 0;
  Int_t    n            = 0;
  
  //unsigned t0, t1;

  void Disable();
  void Enable();
  
 public:
  WMainPE(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options);
  virtual ~WMainPE();  
  
  Double_t GetLength(){return NumEntLength -> GetNumber();}
  Double_t GetRadius(){return NumEntR -> GetNumber();}
  Double_t GetSpeed(){return NumEntV -> GetNumber();}
  Double_t GetOmega(){return NumEntOmega -> GetNumber();}
  Double_t GetTheta(){return NumEntTheta -> GetNumber();}
  Double_t GetMass(){return NumEntMass -> GetNumber();}
  Double_t GetK(){return NumEntK -> GetNumber();}
  Double_t GetG(){return NumEntG -> GetNumber();}

  Double_t CalculateRange();
  Double_t Hamiltonian(); 
  void TBCalculateSimulCliked();
  void ResizeSimulCanvas();
  void DrawBeforeVectors();
  void TBClearCliked();
  void TBPlayCliked();
  void TBExitCliked();
  void DrawSystem();
  void DoDraw();
  
  ClassDef(WMainPE, 0);
};

#endif
//#ifdef __CINT__
//#include "../src/WMainPE.cxx"
//#endif

//__________________________________________________________________________________________________________
//
//EOF
//
