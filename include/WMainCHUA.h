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

#ifndef _CHAOS_WMainCHUA
#define _CHAOS_WMainCHUA

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

class WMainCHUA{
  RQ_OBJECT("WMainCHUA");
 private:
  TRootEmbeddedCanvas *EmbeddedDiagramCanvas, *EmbeddedDiodeFunctCanvas, *EmbeddedAttractorCanvas;
  TRootEmbeddedCanvas *EmbeddedV1TCanvas, *EmbeddedV2TCanvas, *EmbeddedI3TCanvas, *EmbeddedLyapuCanvas;
  TGHorizontalFrame   *HFrame1, *HFrame1111, *HFrame1121, *HFrame1131, *HFrame11311, *HFrame11312;
  TGHorizontalFrame   *HFrame1141, *HFrame1142, *HFrame1151, *HFrame1152, *HFrame116;  
  TGCompositeFrame    *CompFrame1311, *CompFrame1312, *CompFrame1313, *CompFrame1314, *CompFrame1315;
  TGVerticalFrame     *VFrame11, *VFrame12, *VFrame13;
  TGNumberEntry       *NumEntRes1, *NumEntRes2, *NumEntCap1, *NumEntCap2, *NumEntInduc, *NumEntGa;
  TGNumberEntry       *NumEntGb, *NumEntE, *NumEntV1, *NumEntV2, *NumEntI3;
  TGGroupFrame        *GroupRes, *GroupCap, *GroupInduc, *GroupDioPar, *GroupIniCon;
  TGTextButton        *TextButtonCalculate, *TextButtonPlay, *TextButtonClear, *TextButtonExit;
  TGMainFrame         *MainFrame;
  TGLabel             *LabelRes1, *LabelRes2, *LabelCap1, *LabelCap2, *LabelInduc, *LabelGa, *LabelGb;
  TGLabel             *LabelE, *LabelV1, *LabelV2, *LabelI3;
  TCanvas             *CanvasDiagram, *CanvasDiodeFunct, *CanvasAttractor, *CanvasV1T, *CanvasV2T;  
  TCanvas             *CanvasI3T, *CanvasLyapu;
  TGTab               *Tabs;
  
  TMultiGraph         *Exponentes;
  TGraph2D            *TGraph2DAttractor;
  TGraph              *TGraphV1T, *TGraphV2T, *TGraphI3T, *TGraphL1, *TGraphL2, *TGraphL3;
  TTimer              *Cont;
  TImage              *img;
  Int_t               IsActive;
  TF1                 *DiodeFunct;
  
  Double_t Ga = 0.;
  Double_t Gb = 0.;
  Double_t E  = 0.;
  
  Double_t Time = 0.;
  Double_t V1   = 0.;
  Double_t V2   = 0.;
  Double_t I3   = 0.;

  Double_t SeigenvalV1;
  Double_t SeigenvalV2;
  Double_t SeigenvalI3;

  Double_t MeigenvalV1 = 0.;
  Double_t MeigenvalV2 = 0.;
  Double_t MeigenvalI3 = 0.;

  Double_t Time_Matrix[500] = {0.};
  Double_t V1_Matrix[500]   = {0.};
  Double_t V2_Matrix[500]   = {0.};
  Double_t I3_Matrix[500]   = {0.};

  Double_t LV1[500] = {0.};
  Double_t LV2[500] = {0.};
  Double_t LI3[500] = {0.};

  Int_t i = 0, k = 0, n = 0;

  //unsigned t0, t1;
  
  ofstream outfile;
  ifstream infile;
  
  void Disable();
  void Enable();
  
 public:
  WMainCHUA(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options);
  virtual ~WMainCHUA();
  
  Double_t GetR(){return NumEntRes1 -> GetNumber();}
  Double_t GetR_0(){return NumEntRes2 -> GetNumber();}
  Double_t GetC_1(){return NumEntCap1 -> GetNumber();}
  Double_t GetC_2(){return NumEntCap2 -> GetNumber();}
  Double_t GetL(){return NumEntInduc -> GetNumber();}
  Double_t GetV1(){return NumEntV1 -> GetNumber();}
  Double_t GetV2(){return NumEntV2 -> GetNumber();}
  Double_t GetI3(){return NumEntI3 -> GetNumber();}
  void DrawDiodeFunct(); 
  void TBPlayCliked();
  void TBClearCliked();
  void TBExitCliked();
  void TBCalculateSimulCliked();
  void DoDraw();
  
  ClassDef(WMainCHUA, 0);
};

#endif
//#ifdef __CINT__
//#include "../src/WMainCHUA.cxx"
//#endif

//__________________________________________________________________________________________________________
//
//EOF
//
