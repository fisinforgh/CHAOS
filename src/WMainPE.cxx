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

#include "../include/WMainPE.h"

using namespace std;

WMainPE::WMainPE(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options){
  //=======================================================================================================
  //                                               Main Frame
  //=======================================================================================================
  MainFrame = new TGMainFrame(p, w, h, options);
  MainFrame -> Connect("CloseWindow()", "WMainPE", this, "TBExitCliked()");
  MainFrame -> SetName("MainFrame ");
  MainFrame -> SetCleanup(kDeepCleanup);
  MainFrame -> SetWindowName("Spring pendulum");
  MainFrame -> SetIconPixmap("/usr/share/Chaos_V0.1/icon.jpg");
  MainFrame -> SetIconName("CHAOS");
  //=======================================================================================================
  //                                           Horizontal Frame I
  //=======================================================================================================
  HFrame1 = new TGHorizontalFrame(MainFrame, 1081, 382, kHorizontalFrame);
  HFrame1 -> SetName("HFrame1");
  //=======================================================================================================
  //                                           Vertical Frame I, I
  //=======================================================================================================
  VFrame11 = new TGVerticalFrame(HFrame1, 342, 378, kVerticalFrame);
  VFrame11 -> SetName("VFrame11");
  //-------------------------------------------------------------------------------------------------------
  //                                     Pendulum Properties Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro = new TGGroupFrame(VFrame11, "Pendulum Properties");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame M & K
  //-------------------------------------------------------------------------------------------------------
  HFrame1111 = new TGHorizontalFrame(GroupPenPro, 302, 36, kHorizontalFrame);
  //Mass Label---------------------------------------------------------------------------------------------
  LabelMass = new TGLabel(HFrame1111, "Mass[kg]:");
  LabelMass -> SetTextJustify(36);
  LabelMass -> SetMargins(0, 0, 0, 0);
  LabelMass -> SetWrapLength(-1);
  HFrame1111 -> AddFrame(LabelMass, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //Mass Number Entry-------------------------------------------------------------------------------------- 
  NumEntMass = new TGNumberEntry(HFrame1111, (Double_t) 0, 5, -1, TGNumberFormat::kNESReal
				 , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				 , 0.001, 99.0);
  HFrame1111 -> AddFrame(NumEntMass, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntMass -> SetNumber(0.5);
  NumEntMass -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //K Label------------------------------------------------------------------------------------------------
  LabelK = new TGLabel(HFrame1111, "k[N/m]:");
  LabelK -> SetTextJustify(36);
  LabelK -> SetMargins(0, 0, 0, 0);
  LabelK -> SetWrapLength(-1);
  HFrame1111 -> AddFrame(LabelK, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //K Number Entry------------------------------------------------------------------------------------
  NumEntK = new TGNumberEntry(HFrame1111, (Double_t) 0, 5, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , 0.001, 999.0);
  HFrame1111 -> AddFrame(NumEntK, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntK -> SetNumber(10.);
  NumEntK -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> AddFrame(HFrame1111, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //Natural Length Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1112 = new TGHorizontalFrame(GroupPenPro, 302, 36, kHorizontalFrame);
  //Natural Length Label-----------------------------------------------------------------------------------
  LabelLength = new TGLabel(HFrame1112, "Natural Length[m]:");
  LabelLength -> SetTextJustify(36);
  LabelLength -> SetMargins(0, 0, 0, 0);
  LabelLength -> SetWrapLength(-1);
  HFrame1112 -> AddFrame(LabelLength, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Length Number Entry------------------------------------------------------------------------------------
  NumEntLength = new TGNumberEntry(HFrame1112, (Double_t) 0, 5, -1, TGNumberFormat::kNESReal
				   , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				   , 0.001, 10.0);
  HFrame1112 -> AddFrame(NumEntLength, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							 kLHintsCenterY, 2, 2, 2, 2));
  NumEntLength -> SetNumber(1.0);
  NumEntLength -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> AddFrame(HFrame1112, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> SetLayoutManager(new TGVerticalLayout(GroupPenPro));
  GroupPenPro -> Resize(338,112);
  VFrame11 -> AddFrame(GroupPenPro, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                    Simulation Parameters Group Frame
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar = new TGGroupFrame(VFrame11, "Simulation Parameters");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame G & ButtonCheck
  //-------------------------------------------------------------------------------------------------------
  HFrame1121 = new TGHorizontalFrame(GroupSimPar, 302, 36, kHorizontalFrame);
  //Horizontal Frame G-------------------------------------------------------------------------------------
  HFrame11211 = new TGHorizontalFrame(HFrame1121, 148, 32, kHorizontalFrame);
  //g Label------------------------------------------------------------------------------------------------
  LabelG = new TGLabel(HFrame11211, "g[m/s^2]:");
  LabelG -> SetTextJustify(36);
  LabelG -> SetMargins(0, 0, 0, 0);
  LabelG -> SetWrapLength(-1);
  HFrame11211 -> AddFrame(LabelG, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //g Number Entry-----------------------------------------------------------------------------------------
  NumEntG = new TGNumberEntry(HFrame11211,  (Double_t) 0, 6, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , 0.0, 24.8);
  HFrame11211 -> AddFrame(NumEntG, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX,2,2,2,2));
  NumEntG -> SetNumber(9.81);
  NumEntG -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  HFrame1121 -> AddFrame(HFrame11211, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Horizontal Frame ButtonCheck---------------------------------------------------------------------------
  HFrame11212 = new TGHorizontalFrame(HFrame1121, 148, 32, kHorizontalFrame);
  //Vectors Check Button-----------------------------------------------------------------------------------
  CheckButtonVectors = new TGCheckButton(HFrame11212, "Show Vectors");
  CheckButtonVectors -> SetTextJustify(36);
  CheckButtonVectors -> SetMargins(0, 0, 0, 0);
  CheckButtonVectors -> SetWrapLength(-1);
  HFrame11212 -> AddFrame(CheckButtonVectors, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
								kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
								, 2, 2, 2, 2));
  CheckButtonVectors -> SetState(kButtonDown, kTRUE);
  //-------------------------------------------------------------------------------------------------------
  HFrame1121 ->AddFrame(HFrame11212, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                       , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> AddFrame(HFrame1121, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                        kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                        , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //Calculate Button Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame1122 = new TGHorizontalFrame(GroupSimPar, 302, 36, kHorizontalFrame);
  //Calculate Button---------------------------------------------------------------------------------------
  TextButtonCalculate = new TGTextButton(HFrame1122, "&Calculate", -1, TGTextButton::GetDefaultGC()()
					 , TGTextButton::GetDefaultFontStruct() ,kRaisedFrame);
  TextButtonCalculate -> SetTextJustify(36);  
  TextButtonCalculate -> SetMargins(0, 0, 0, 0);
  TextButtonCalculate -> SetWrapLength(-1);
  TextButtonCalculate -> Resize(298, 32);
  HFrame1122 -> AddFrame(TextButtonCalculate, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
                                                                kLHintsTop | kLHintsCenterY |
                                                                kLHintsExpandX | kLHintsExpandY
                                                                , 2, 2, 2, 2));
  TextButtonCalculate -> Connect("Clicked()", "WMainPE", this, "TBCalculateSimulCliked()");
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> AddFrame(HFrame1122, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                        kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                        , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> SetLayoutManager(new TGVerticalLayout(GroupSimPar));
  GroupSimPar -> Resize(338, 112);
  VFrame11 -> AddFrame(GroupSimPar, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                     Initial Conditions Group Frame
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon = new TGGroupFrame(VFrame11, "Initial Conditions");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame Theta(0) & Omega(0)
  //-------------------------------------------------------------------------------------------------------
  HFrame1131 = new TGHorizontalFrame(GroupIniCon, 302, 36, kHorizontalFrame);
  //Theta Label--------------------------------------------------------------------------------------------
  LabelTheta = new TGLabel(HFrame1131, "Theta[rad]:");
  LabelTheta -> SetTextJustify(36);
  LabelTheta -> SetMargins(0, 0, 0, 0);
  LabelTheta -> SetWrapLength(-1);
  HFrame1131 -> AddFrame(LabelTheta, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                       , 2, 2, 2, 2));
  //Theta Number Entry-------------------------------------------------------------------------------------
  NumEntTheta = new TGNumberEntry(HFrame1131, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
				  , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				  , -TMath::Pi(), TMath::Pi());
  HFrame1131 -> AddFrame(NumEntTheta, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                        kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntTheta -> SetNumber(3.0);
  NumEntTheta -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //Omega Label--------------------------------------------------------------------------------------------
  LabelOmega = new TGLabel(HFrame1131, "Omega[rad/s]:");
  LabelOmega -> SetTextJustify(36);
  LabelOmega -> SetMargins(0, 0, 0, 0);
  LabelOmega -> SetWrapLength(-1);
  HFrame1131 -> AddFrame(LabelOmega, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                       , 2, 2, 2, 2));
  //Omega Number Entry-------------------------------------------------------------------------------------
  NumEntOmega = new TGNumberEntry(HFrame1131, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
				  , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				  , -99, 99);
  HFrame1131->AddFrame(NumEntOmega, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                      kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntOmega -> SetNumber(3.0);
  NumEntOmega -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon->AddFrame(HFrame1131, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame R(0) & V(0)
  //-------------------------------------------------------------------------------------------------------
  HFrame1132 = new TGHorizontalFrame(GroupIniCon, 302, 36, kHorizontalFrame);
  //R Label------------------------------------------------------------------------------------------------
  LabelR = new TGLabel(HFrame1132, "R[m]:");
  LabelR -> SetTextJustify(36);
  LabelR -> SetMargins(0, 0, 0, 0);
  LabelR -> SetWrapLength(-1);
  HFrame1132 -> AddFrame(LabelR, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                   , 2, 2, 2, 2));
  //R Number Entry-----------------------------------------------------------------------------------------
  NumEntR = new TGNumberEntry(HFrame1132,  (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , -10.0, 10.0);
  HFrame1132 -> AddFrame(NumEntR, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntR -> SetNumber(0.01);
  NumEntR -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //V Label------------------------------------------------------------------------------------------------
  LabelV = new TGLabel(HFrame1132, "V[m/s]:");
  LabelV -> SetTextJustify(36);
  LabelV -> SetMargins(0, 0, 0, 0);
  LabelV -> SetWrapLength(-1);
  HFrame1132->AddFrame(LabelV, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                 kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                 , 2, 2, 2, 2));
  //V Number Entry-----------------------------------------------------------------------------------------
  NumEntV = new TGNumberEntry(HFrame1132, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , -99, 99);
  HFrame1132 -> AddFrame(NumEntV, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntV -> SetNumber(-3.0);
  NumEntV -> Connect("ValueSet(Long_t)", "WMainPE", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> AddFrame(HFrame1132, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> SetLayoutManager(new TGVerticalLayout(GroupIniCon));
  GroupIniCon -> Resize(338, 112);
  VFrame11 -> AddFrame(GroupIniCon, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                         Buttons Horizontal Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame114 = new TGHorizontalFrame(VFrame11, 338, 26, kHorizontalFrame);
  HFrame114->SetName("HFrame114");
  //Play Button--------------------------------------------------------------------------------------------
  TextButtonPlay = new TGTextButton(HFrame114, "&Play", -1, TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonPlay -> SetTextJustify(36);
  TextButtonPlay -> SetMargins(0, 0, 0, 0);
  TextButtonPlay -> SetWrapLength(-1);
  TextButtonPlay -> Resize(108, 22);
  HFrame114 -> AddFrame(TextButtonPlay, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                          kLHintsExpandX, 2, 2, 2, 2));
  TextButtonPlay -> Connect("Clicked()", "WMainPE", this, "TBPlayCliked()");
  //Clear Button-------------------------------------------------------------------------------------------
  TextButtonClear = new TGTextButton(HFrame114, "&Clear", -1, TGTextButton::GetDefaultGC()()
				     , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonClear -> SetTextJustify(36);
  TextButtonClear -> SetMargins(0, 0, 0, 0);
  TextButtonClear -> SetWrapLength(-1);
  TextButtonClear -> Resize(109, 22);
  HFrame114 -> AddFrame(TextButtonClear, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                           kLHintsExpandX, 2, 2, 2, 2));
  TextButtonClear -> Connect("Clicked()", "WMainPE", this, "TBClearCliked()");
  //Exit Button--------------------------------------------------------------------------------------------
  TextButtonExit = new TGTextButton(HFrame114,"&Exit", -1, TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonExit -> SetTextJustify(36);
  TextButtonExit -> SetMargins(0, 0, 0, 0);
  TextButtonExit -> SetWrapLength(-1);
  TextButtonExit -> Resize(109, 22);
  HFrame114 -> AddFrame(TextButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                          kLHintsExpandX, 2, 2, 2, 2));
  TextButtonExit -> Connect("Clicked()", "WMainPE", this, "TBExitCliked()");
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(HFrame114, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                    kLHintsExpandX, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame11, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | 
                                                  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                  , 2, 2, 2, 2));
  //=======================================================================================================
  //                                           Vertical Frame I, II
  //=======================================================================================================
  VFrame12 = new TGVerticalFrame(HFrame1, 343, 378, kVerticalFrame);
  VFrame12 -> SetName("VFrame12");
  //-------------------------------------------------------------------------------------------------------
  //                                             Simulation Cavas
  //-------------------------------------------------------------------------------------------------------
  EmbeddedSimulCanvas = new TRootEmbeddedCanvas(0, VFrame12, 339, 374, kSunkenFrame);
  EmbeddedSimulCanvas -> SetName("EmbeddedSimulCanvas");
  Int_t wEmbeddedSimulCanvas = EmbeddedSimulCanvas -> GetCanvasWindowId();
  CanvasSimul = new TCanvas("CanvasSimul", 10, 10, wEmbeddedSimulCanvas);
  CanvasSimul -> ToggleEditor();
  CanvasSimul -> SetFillColor(kWhite);

  //Pendulum Draw------------------------------------------------------------------------------------------
  DrawSystem();
  //-------------------------------------------------------------------------------------------------------
  EmbeddedSimulCanvas -> AdoptCanvas(CanvasSimul);
  VFrame12 -> AddFrame(EmbeddedSimulCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                              kLHintsCenterY | kLHintsExpandX | 
                                                              kLHintsExpandY, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame12, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
                                                  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
                                                  , 2, 2, 2, 2));
  //=======================================================================================================
  //                                           Vertical Frame I, III
  //=======================================================================================================
  VFrame13 = new TGVerticalFrame(HFrame1, 343, 378, kVerticalFrame);
  VFrame13 -> SetName("VFrame13");
  //=======================================================================================================
  //                                           Tabs I - III
  //=======================================================================================================
  Tabs = new TGTab(VFrame13, 339, 374);
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab1
  //-------------------------------------------------------------------------------------------------------
  CompFrame1311 = Tabs -> AddTab("Radial Phase-Space");
  CompFrame1311 -> SetLayoutManager(new TGVerticalLayout(CompFrame1311));
  // embedded canvas
  EmbeddedFaseRCanvas = new TRootEmbeddedCanvas(0, CompFrame1311, 331, 345, kSunkenFrame);
  Int_t wEmbeddedFaseRCanvas = EmbeddedFaseRCanvas -> GetCanvasWindowId();
  CanvasFaseR = new TCanvas("CanvasFaseR", 10, 10, wEmbeddedFaseRCanvas);
  CanvasFaseR -> ToggleEditor();
  CanvasFaseR -> SetFillColor(kWhite);
  CanvasFaseR -> SetGrid();
  
  EmbeddedFaseRCanvas -> AdoptCanvas(CanvasFaseR);
  CompFrame1311 -> AddFrame(EmbeddedFaseRCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | 
                                                                   kLHintsTop | kLHintsCenterY | 
                                                                   kLHintsExpandX | kLHintsExpandY
                                                                   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab2
  //-------------------------------------------------------------------------------------------------------
  CompFrame1312 = Tabs -> AddTab("Angular Phase-Space");
  CompFrame1312 -> SetLayoutManager(new TGVerticalLayout(CompFrame1312));
  // embedded canvas
  EmbeddedFaseACanvas = new TRootEmbeddedCanvas(0, CompFrame1312, 331, 345, kSunkenFrame);
  Int_t wEmbeddedFaseACanvas = EmbeddedFaseACanvas -> GetCanvasWindowId();
  CanvasFaseA = new TCanvas("CanvasFaseA", 10, 10, wEmbeddedFaseACanvas);
  CanvasFaseA -> ToggleEditor();
  CanvasFaseA -> SetFillColor(kWhite);
  CanvasFaseA -> SetGrid();
  
  EmbeddedFaseACanvas -> AdoptCanvas(CanvasFaseA);
  CompFrame1312 -> AddFrame(EmbeddedFaseACanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
                                                                   kLHintsTop | kLHintsCenterY | 
                                                                   kLHintsExpandX | kLHintsExpandY
                                                                   , 2, 2, 2, 2));

  //-------------------------------------------------------------------------------------------------------
  //                                        Container Tab3
  //-------------------------------------------------------------------------------------------------------
  CompFrame1313 = Tabs -> AddTab("Lyapunov");
  CompFrame1313 -> SetLayoutManager(new TGVerticalLayout(CompFrame1313));
  // embedded canvas
  EmbeddedLyapuCanvas = new TRootEmbeddedCanvas(0, CompFrame1313, 331, 345, kSunkenFrame);
  Int_t wEmbeddedLyapuCanvas = EmbeddedLyapuCanvas -> GetCanvasWindowId();
  CanvasLyapu = new TCanvas("CanvasLyapu", 10, 10, wEmbeddedLyapuCanvas);
  CanvasLyapu -> ToggleEditor();
  CanvasLyapu -> SetFillColor(kWhite);
  CanvasLyapu -> SetGrid();
  
  EmbeddedLyapuCanvas -> AdoptCanvas(CanvasLyapu);
  CompFrame1313 -> AddFrame(EmbeddedLyapuCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
                                                                   kLHintsTop | kLHintsCenterY | 
                                                                   kLHintsExpandX | kLHintsExpandY
                                                                   , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  Tabs -> SetTab(0);
  
  Tabs -> Resize(Tabs -> GetDefaultSize());
  VFrame13 -> AddFrame(Tabs, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop | kLHintsCenterY |
                                               kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2));
  //=======================================================================================================
  HFrame1 -> AddFrame(VFrame13, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						  , 2, 2, 2, 2));
  //=======================================================================================================
  MainFrame -> AddFrame(HFrame1 , new TGLayoutHints(kLHintsCenterX | kLHintsCenterY | kLHintsExpandX |
                                                    kLHintsExpandY, 1, 1, 1, 1));
  
  MainFrame -> SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
  MainFrame -> MapSubwindows();
  MainFrame -> Resize(MainFrame ->GetDefaultSize());
  MainFrame -> Resize(1081, 384);
  MainFrame -> MapWindow();
  //=======================================================================================================
  Cont = new TTimer(100);
  Cont -> Connect("Timeout()","WMainPE",this,"DoDraw()");
  IsActive = -1;
}

//========================================================================================================
//CALCULATE THE SYSTEM ENERGY
//========================================================================================================

Double_t WMainPE::Hamiltonian(){
  H = 0.5*GetMass()*TMath::Power(GetSpeed(), 2.) +
    0.5*GetMass()*TMath::Power(GetLength() + GetRadius(), 2.)*TMath::Power(GetOmega(), 2.) -
    GetMass()*GetG()*(GetLength() + GetRadius())*TMath::Cos(GetTheta()) 
    + 0.5*GetK()*TMath::Power(GetRadius(), 2.);
  return H;
}

//========================================================================================================
//CALCULATE THE RANGE OF THE SIMULATION
//========================================================================================================

Double_t WMainPE::CalculateRange(){
  Discriminant = TMath::Power(GetMass()*GetG(), 2.)
    + 2.*GetK()*(GetMass()*GetG()*GetLength() + Hamiltonian());
  if(Discriminant == 0.){
    Rho_1 = (GetMass()*GetG())/GetK();
    Rho_2 = Rho_1;
    return 1.3*(Rho_1 + GetLength());
  }
  else if(Discriminant > 0.){
    Rho_1 = (GetMass()*GetG() + TMath::Sqrt(Discriminant))/GetK();
    Rho_2 = (GetMass()*GetG() - TMath::Sqrt(Discriminant))/GetK();
    return 1.3*(Rho_1 + GetLength());
  }
  else if(Discriminant < 0.){
    return 3.0*GetLength();
  }
}

//========================================================================================================
//RESIZE CANVAS OF THE SIMULATION
//========================================================================================================

void WMainPE::ResizeSimulCanvas(){
  CanvasSimul -> cd();
  CanvasSimul -> Range(-1.3*CalculateRange(), -1.3*CalculateRange()
		       , 1.3*CalculateRange(), 1.3*CalculateRange());
}

void WMainPE::DrawSystem(){
  ResizeSimulCanvas();
  
  Box  = new TBox();
  Box -> SetFillColor(28);
  
  Spring = new TCurlyLine();
  Spring -> SetStartPoint(0., 0.);
  Spring -> SetAmplitude(0.01);
  //Spring -> SetAmplitude(GetLength()/100.);
  Spring -> SetWaveLength((GetLength() + GetRadius())/300.);
  
  Lentil = new TEllipse();
  Lentil -> SetFillColor(3);
  Lentil -> SetPhimin(0.);
  Lentil -> SetPhimax(360.);
  
  Box -> SetX1(-GetLength()/2.);
  Box -> SetY1(-GetLength()/15.);
  Box -> SetX2(GetLength()/2.);
  Box -> SetY2(GetLength()/15.);
  
  Spring -> SetEndPoint((GetLength() + GetRadius())*TMath::Sin(GetTheta()),
			-(GetLength() + GetRadius())*TMath::Cos(GetTheta()));
  
  Lentil -> SetX1((GetLength() + GetRadius())*TMath::Sin(GetTheta()));
  Lentil -> SetY1(-(GetLength() + GetRadius())*TMath::Cos(GetTheta()));
  Lentil -> SetR1(GetLength()/10.);
  Lentil -> SetR2(GetLength()/10.);

  DrawBeforeVectors();
  
  CanvasSimul -> cd();

  Box -> Draw();
  Spring -> Draw();
  Lentil -> Draw();
  ArrowWeight -> Draw();
  ArrowStress -> Draw();
  
  CanvasSimul -> Modified();
  CanvasSimul -> Update();
  
  delete Box;
  delete Spring;
  delete Lentil;
  delete ArrowWeight;
  delete ArrowStress;
}


void WMainPE::DrawBeforeVectors(){
  //-------------------------------------------------------------------------------------------------------
  
  ArrowWeight = new TArrow();
  ArrowWeight -> SetLineColor(2);
  ArrowWeight -> SetFillColor(2);
  ArrowWeight -> SetLineWidth(1);
  ArrowWeight -> SetOption("->");

  ArrowStress = new TArrow();
  ArrowStress -> SetLineColor(4);
  ArrowStress -> SetFillColor(4);
  ArrowStress -> SetLineWidth(1);
  ArrowStress -> SetOption("->");

  if(CheckButtonVectors -> IsDown()){
    
    ArrowWeight -> SetX1((GetLength() + GetRadius())*TMath::Sin(GetTheta()));
    ArrowWeight -> SetY1(-(GetLength() + GetRadius())*TMath::Cos(GetTheta()));
    
    ArrowWeight -> SetX2((GetLength() + GetRadius())*TMath::Sin(GetTheta()));
    ArrowWeight -> SetY2(-(GetLength() + GetRadius())*TMath::Cos(GetTheta()) - 0.1*GetMass()*GetG());
    
    if((TMath::Abs((GetLength() + GetRadius())*TMath::Sin(GetTheta())) <= CalculateRange()) ||
       (TMath::Abs(-(GetLength() + GetRadius())*TMath::Cos(GetTheta()) - 0.1*GetMass()*GetG()) <=
	CalculateRange())){
      ArrowWeight -> SetArrowSize(0.02); ArrowWeight -> SetOption("|>");
    }
    else{
      ArrowWeight -> SetOption("");
    }
    
    
    ArrowStress -> SetX1((GetLength() + GetRadius())*TMath::Sin(GetTheta()));
    ArrowStress -> SetY1(-(GetLength() + GetRadius())*TMath::Cos(GetTheta()));
    
    ArrowStress -> SetX2((GetLength() + GetRadius() - 0.1*GetK()*GetRadius())*TMath::Sin(GetTheta()));
    ArrowStress -> SetY2(-(GetLength() + GetRadius() - 0.1*GetK()*GetRadius())*TMath::Cos(GetTheta()));
    
    if((TMath::Abs((GetLength() + GetRadius() - 0.1*GetK()*GetRadius())*TMath::Sin(GetTheta())) <=
	CalculateRange())
       || (TMath::Abs(-(GetLength() + GetRadius() - 0.1*GetK()*GetRadius())*TMath::Cos(GetTheta()))
	   <= CalculateRange())){
      ArrowStress -> SetArrowSize(0.02); ArrowStress -> SetOption("|>");
    }
    else{
      ArrowStress -> SetOption("");
    }
  }
  
  if(!CheckButtonVectors -> IsDown()){
    
    ArrowWeight -> SetX1(0.0); ArrowWeight -> SetY1(0.0);
    ArrowWeight -> SetX2(0.0); ArrowWeight -> SetY2(0.0);
    
    ArrowStress -> SetX1(0.0); ArrowStress -> SetY1(0.0);
    ArrowStress -> SetX2(0.0); ArrowStress -> SetY2(0.0);  
  }
} 

void WMainPE::TBCalculateSimulCliked(){
  CanvasSimul -> cd();
  TText * text = new TText(0.0, 0.0, "Estimating...");
  text -> SetTextAlign(22);
  text -> SetTextSize(0.05);
  text -> Draw();
  CanvasSimul -> Update();
  
  outfile.open("/tmp/Penlas.m");
  
  Omega   = GetOmega();
  Theta   = GetTheta();
  Speed   = GetSpeed();
  Rho     = GetRadius();
  Mass    = GetMass();
  K       = GetK();
  Length  = GetLength();
  G       = GetG();
  
  //=======================================================================================================
  //OCTAVE SCRIPT 
  //=======================================================================================================
  outfile << "## Solve Diferencial Equation" << endl;
  outfile << "x = 0.;"<< endl;
  outfile << "t = 0.;"<< endl;
  outfile << "function xdot = f(x,t)" << endl;
  outfile << "    xdot(1) = ((x(3)^2)/(" << setprecision(15) << Mass << "*(("
	  << setprecision(15) << Length << " + x(2))^3.0))) - " << setprecision(15) << K << "*x(2) + "
	  << setprecision(15) << Mass*G << "*cos(x(4));" << endl;
  outfile << "    xdot(2) = x(1)/" << setprecision(15) << Mass << ";" << endl;
  outfile << "    xdot(3) = - " << setprecision(15) << Mass*G << "*("
	  << setprecision(15) << Length << " + x(2))*sin(x(4));" << endl;
  outfile << "    xdot(4) = ((x(3))/(" << setprecision(15) << Mass << "*(("
	  << setprecision(15) << Length << " + x(2))^2.0)));" << endl;
  outfile << "endfunction" << endl;
  outfile << "x=lsode('f',[" << setprecision(15) << Mass*Speed << ";" << setprecision(15) << Rho << ";"
	  << setprecision(15) << Omega*Mass*TMath::Power(Length + Rho, 2.) << ";"
	  << setprecision(15) << Theta << "],(t=linspace(0.0,"
	  << setprecision(15) << 1000.0*TMath::Sqrt((Length*K)/(Mass*G) + 1.) << ",1000000)'));" << endl;
  outfile << "M=[t,x];" << endl;
  outfile << "dlmwrite('/tmp/Penlas.dat',M,'\t');" << endl;
  
  outfile.close();
  
  system("octave -q /tmp/Penlas.m");
  
  delete text;
  DrawSystem();
  infile.open("/tmp/Penlas.dat");  

}

void WMainPE::Disable(){
  TextButtonCalculate -> SetEnabled(kFALSE);
  NumEntMass          -> SetState(kFALSE);
  NumEntK             -> SetState(kFALSE);
  NumEntLength        -> SetState(kFALSE);
  NumEntG             -> SetState(kFALSE);
  NumEntTheta         -> SetState(kFALSE);
  NumEntOmega         -> SetState(kFALSE);
  NumEntR             -> SetState(kFALSE);
  NumEntV             -> SetState(kFALSE);
}

void WMainPE::Enable(){
  TextButtonCalculate -> SetEnabled(kTRUE);
  NumEntMass          -> SetState(kTRUE);
  NumEntK             -> SetState(kTRUE);
  NumEntLength        -> SetState(kTRUE);
  NumEntG             -> SetState(kTRUE);
  NumEntTheta         -> SetState(kTRUE);
  NumEntOmega         -> SetState(kTRUE);
  NumEntR             -> SetState(kTRUE);
  NumEntV             -> SetState(kTRUE);
}

void WMainPE::TBPlayCliked(){
  if(IsActive == -1){
    TextButtonPlay -> SetText("&Pause");
    Cont -> TurnOn();
    Disable();
    IsActive = 0;
  }
  else if(IsActive == 0){
    TextButtonPlay -> SetText("&Continue");
    TextButtonClear -> SetEnabled(kTRUE);
    Cont -> TurnOff();
    
    IsActive = 1;
  }
  else if(IsActive == 1){
    TextButtonPlay -> SetText("&Pause");
    TextButtonClear -> SetEnabled(kFALSE);
    Cont -> TurnOn();
    
    IsActive = 0;
  }
}

void WMainPE::TBClearCliked(){
  Enable();
  infile.close();
  k = 0; n = 0;

  SeigenvalP     = 0.;
  SeigenvalRho   = 0.;
  SeigenvalL     = 0.;
  SeigenvalTheta = 0.;
  
  for(j = 0; j <= 199; j ++){
    Omega_Matrix[j] = 0.;
    Theta_Matrix[j] = 0.;
    Radial_Matrix[j] = 0.;
    Speed_Matrix[j] = 0.;
    
    T[j]      = 0.;
    LP[j]     = 0.;
    LRho[j]   = 0.;
    LL[j]     = 0.;
    LTheta[j] = 0.; 
  }
  j = 0;
  IsActive = -1;
}

void WMainPE::DoDraw(){
  for(k = 0; k < 25; k ++){
    n ++;
    
    infile >> Time;
    infile >> P;
    infile >> Rho;
    infile >> L;
    infile >> Theta;
    //=======================================================================================================
    // JACOBIAN MATRIX
    //=======================================================================================================
    TMatrixD J(4, 4);
    
    J(0,0) = 0.;
    J(0,1) = (-3.*TMath::Power(L, 2.)
	      /(GetMass()*TMath::Power((NumEntLength -> GetNumber() + Rho), 2.))) - GetK();
    J(0,2) = (2.*L/(GetMass()*TMath::Power((NumEntLength -> GetNumber() + Rho), 3.)));
    J(0,3) = -GetMass()*GetG()*TMath::Sin(Theta);
    J(1,0) = 1.0/GetMass();
    J(1,1) = 0.;
    J(1,2) = 0.;
    J(1,3) = 0.;
    J(2,0) = 0.;
    J(2,1) = -GetMass()*GetG()*TMath::Sin(Theta);
    J(2,2) = 0.;
    J(2,3) = -GetMass()*GetG()*(NumEntLength -> GetNumber() + Rho)*TMath::Cos(Theta);
    J(3,0) = 0.;
    J(3,1) = (-2.*L/(GetMass()*TMath::Power((NumEntLength -> GetNumber() + Rho), 3.)));
    J(3,2) = (1./(GetMass()*TMath::Power((NumEntLength -> GetNumber() + Rho), 3.)));
    J(3,3) = 0.;
    //-------------------------------------------------------------------------------------------------------
    //CALCULATION OF OWN VALUES
    //-------------------------------------------------------------------------------------------------------
    TMatrixDEigen me(J);
    TVectorD eigenval = me.GetEigenValuesRe();
    
    SeigenvalP     += eigenval(0);
    SeigenvalRho   += eigenval(1);
    SeigenvalL     += eigenval(2);
    SeigenvalTheta += eigenval(3);
    //-------------------------------------------------------------------------------------------------------
    //AVERAGE
    //-------------------------------------------------------------------------------------------------------
    MeigenvalP     = SeigenvalP/(Double_t)n;
    MeigenvalRho   = SeigenvalRho/(Double_t)n;
    MeigenvalL     = SeigenvalL/(Double_t)n;
    MeigenvalTheta = SeigenvalTheta/(Double_t)n;   

  }
  
  NumEntOmega -> SetNumber(L/(GetMass()*TMath::Power((GetLength() + Rho), 2.)));
  NumEntTheta -> SetNumber(TMath::ATan2(TMath::Sin(Theta), TMath::Cos(Theta)));
  NumEntV -> SetNumber(P/(GetMass()));
  NumEntR -> SetNumber(Rho);
  
  Omega_Matrix[j%200] = L;
  Theta_Matrix[j%200] = TMath::ATan2(TMath::Sin(Theta), TMath::Cos(Theta));
  Radial_Matrix[j%200] = Rho;
  Speed_Matrix[j%200] = P;
  
  T[j%200]      = Time;
  LP[j%200]     = MeigenvalP;
  LRho[j%200]   = MeigenvalRho;
  LL[j%200]     = MeigenvalL;
  LTheta[j%200] = MeigenvalTheta; 
  
  j ++;
  
  CanvasFaseR -> cd();
  
  TGraphPhaseR = new TGraph(200, Radial_Matrix, Speed_Matrix);
  
  TGraphPhaseR -> SetTitle("r Vs. P");
  TGraphPhaseR -> SetMarkerColor(2);
  TGraphPhaseR -> SetMarkerStyle(20);
  TGraphPhaseR -> SetMarkerSize(0.5);
  
  TGraphPhaseR -> GetXaxis() -> SetTitle("r(m)");
  TGraphPhaseR -> GetYaxis() -> SetTitle("P(kg*m/s)");
  TGraphPhaseR -> GetXaxis() -> SetLabelSize(0.05);
  TGraphPhaseR -> GetYaxis() -> SetLabelSize(0.05);
  TGraphPhaseR -> Draw("AP");
  CanvasFaseR -> Modified();
  CanvasFaseR -> Update();
  delete TGraphPhaseR;
  
  CanvasFaseA -> cd();
  
  TGraphPhaseA = new TGraph(200, Theta_Matrix, Omega_Matrix);
  
  TGraphPhaseA -> SetTitle("#theta Vs. L");
  TGraphPhaseA -> SetMarkerColor(4);
  TGraphPhaseA -> SetMarkerStyle(20);
  TGraphPhaseA -> SetMarkerSize(0.5);
  
  TGraphPhaseA -> GetXaxis()->SetRangeUser(-4.0,4.0);
  TGraphPhaseA -> GetXaxis()->SetTitle("#theta");
  TGraphPhaseA -> GetYaxis()->SetTitle("L");
  TGraphPhaseA -> GetXaxis() -> SetLabelSize(0.05);
  TGraphPhaseA -> GetYaxis() -> SetLabelSize(0.05);

  TGraphPhaseA -> Draw("AP");
  CanvasFaseA -> Modified();
  CanvasFaseA -> Update();
  delete TGraphPhaseA;
  
  CanvasLyapu -> cd();
  Exponentes = new TMultiGraph();
  Exponentes -> GetXaxis() -> SetTitle("t(s)");
  Exponentes -> GetYaxis() -> SetTitle("#lambda");
  Exponentes -> GetXaxis() -> SetLabelSize(0.05);
  Exponentes -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL1 = new TGraph(200, T, LP);
  TGraphL1 -> SetTitle("#lambda_{p}");
  TGraphL1 -> SetMarkerColor(4);
  TGraphL1 -> SetMarkerStyle(20);
  TGraphL1 -> SetMarkerSize(0.5);
  TGraphL1 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL1 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL2 = new TGraph(200, T, LRho);
  TGraphL2 -> SetTitle("#lambda_{r}");
  TGraphL2 -> SetMarkerColor(5);
  TGraphL2 -> SetMarkerStyle(20);
  TGraphL2 -> SetMarkerSize(0.5);
  TGraphL2 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL2 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL3 = new TGraph(200, T, LL);
  TGraphL3 -> SetTitle("#lambda_{L}");
  TGraphL3 -> SetMarkerColor(6);
  TGraphL3 -> SetMarkerStyle(20);
  TGraphL3 -> SetMarkerSize(0.5);
  TGraphL3 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL3 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL4 = new TGraph(200, T, LTheta);
  TGraphL4 -> SetTitle("#lambda_{#theta}");
  TGraphL4 -> SetMarkerColor(7);
  TGraphL4 -> SetMarkerStyle(20);
  TGraphL4 -> SetMarkerSize(0.5);
  TGraphL4 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL4 -> GetYaxis() -> SetLabelSize(0.05);

  Exponentes -> Add(TGraphL1);
  Exponentes -> Add(TGraphL2);
  Exponentes -> Add(TGraphL3);
  Exponentes -> Add(TGraphL4);
  
  Exponentes -> Draw("ap");
  CanvasLyapu -> BuildLegend();
  CanvasLyapu -> Modified();
  CanvasLyapu -> Update();
  
  //delete Exponentes;
  delete TGraphL1;
  delete TGraphL2;
  delete TGraphL3;
  delete TGraphL4;
  delete Exponentes;

  DrawSystem(); 
}

void WMainPE::TBExitCliked(){
  //-------------------------------------------------------------------------------------------------------
  // Stop the simulation and finish the application
  //-------------------------------------------------------------------------------------------------------
  Cont -> TurnOff();
  MainFrame -> CloseWindow();
}

WMainPE::~WMainPE(){
  MainFrame -> Cleanup();
  delete MainFrame;
}
