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

#include "../include/WMainPAM.h"

using namespace std;

WMainPAM::WMainPAM(const TGWindow *p, UInt_t w, UInt_t h, UInt_t options){
  //=======================================================================================================
  //                                               Main Frame
  //=======================================================================================================
  MainFrame = new TGMainFrame(p, w, h, options);
  MainFrame -> Connect("CloseWindow()","WMainPAM",this,"TBExitCliked()");
  MainFrame -> SetName("MainFrame");
  MainFrame -> SetCleanup(kDeepCleanup);
  MainFrame -> SetWindowName("Pendulum");
  MainFrame -> SetIconPixmap("/usr/share/Chaos_V0.1/icon.jpg");
  MainFrame -> SetIconName("CHAOS");
  //=======================================================================================================
  //                                           Horizontal Frame I
  //=======================================================================================================
  HFrame1 = new TGHorizontalFrame(MainFrame, 1079, 444,kHorizontalFrame);
  HFrame1 -> SetName("HFrame1");
  //=======================================================================================================
  //                                           Vertical Frame I, I
  //=======================================================================================================
  VFrame11 = new TGVerticalFrame(HFrame1, 355, 440, kVerticalFrame);
  VFrame11 -> SetName("VFrame11");
  //-------------------------------------------------------------------------------------------------------
  //                                     Pendulum Properties Group Frame 
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro = new TGGroupFrame(VFrame11, "Pendulum Properties");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame M & L
  //-------------------------------------------------------------------------------------------------------
  HFrame1111 = new TGHorizontalFrame(GroupPenPro, 315, 29, kHorizontalFrame);
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
				 , 0.001, 100.0);
  HFrame1111 -> AddFrame(NumEntMass, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntMass -> SetNumber(0.5);
  NumEntMass -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //Length Label-------------------------------------------------------------------------------------------
  LabelLength = new TGLabel(HFrame1111, "Length[m]:");
  LabelLength -> SetTextJustify(36);
  LabelLength -> SetMargins(0, 0, 0, 0);
  LabelLength -> SetWrapLength(-1);
  HFrame1111 -> AddFrame(LabelLength, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Length Number Entry------------------------------------------------------------------------------------
  NumEntLength = new TGNumberEntry(HFrame1111, (Double_t) 0, 5, -1, TGNumberFormat::kNESReal
				   , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				   , 0.001, 100.0);
  HFrame1111 -> AddFrame(NumEntLength, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							 kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntLength -> SetNumber(1.0);
  NumEntLength -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> AddFrame(HFrame1111, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2)); 
  //-------------------------------------------------------------------------------------------------------
  // Horizontal Frame R
  //-------------------------------------------------------------------------------------------------------
  HFrame1112 = new TGHorizontalFrame(GroupPenPro, 315, 29, kHorizontalFrame);
  //Radius Label-------------------------------------------------------------------------------------------
  LabelRadius = new TGLabel(HFrame1112, "Radius[m]:");
  LabelRadius -> SetTextJustify(36);
  LabelRadius -> SetMargins(0, 0, 0, 0);
  LabelRadius -> SetWrapLength(-1);
  HFrame1112 -> AddFrame(LabelRadius, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Radius Number Entry------------------------------------------------------------------------------------
  NumEntRadius = new TGNumberEntry(HFrame1112, (Double_t) 0, 5, -1, TGNumberFormat::kNESReal
				   , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				   , 0.001, 100.0);
  HFrame1112 -> AddFrame(NumEntRadius, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							 kLHintsCenterY, 2, 2, 2, 2));
  NumEntRadius -> SetNumber(0.1);
  NumEntRadius -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> AddFrame(HFrame1112, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));  
  //-------------------------------------------------------------------------------------------------------
  GroupPenPro -> SetLayoutManager(new TGVerticalLayout(GroupPenPro));
  GroupPenPro -> Resize(351, 98);
  VFrame11 -> AddFrame(GroupPenPro, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                      Medium Properties Group Frame
  //-------------------------------------------------------------------------------------------------------
  GroupMedPro = new TGGroupFrame(VFrame11, "Medium Properties");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame Rho & C
  //-------------------------------------------------------------------------------------------------------
  HFrame1121 = new TGHorizontalFrame(GroupMedPro, 315, 63, kHorizontalFrame);
  //Rho Label----------------------------------------------------------------------------------------------
  LabelRho = new TGLabel(HFrame1121, "Rho[kg/m^3]:");
  LabelRho -> SetTextJustify(36);
  LabelRho -> SetMargins(0, 0, 0, 0);
  LabelRho -> SetWrapLength(-1);
  HFrame1121 -> AddFrame(LabelRho, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						     , 2, 2, 2, 2));
  //Rho Number Entry---------------------------------------------------------------------------------------
  NumEntRho = new TGNumberEntry(HFrame1121, (Double_t) 0, 7, -1, TGNumberFormat::kNESReal
				, TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				, 0.0, 13600.0);
  HFrame1121 -> AddFrame(NumEntRho, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntRho -> SetNumber(1.225);
  NumEntRho -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //C Label------------------------------------------------------------------------------------------------
  LabelC = new TGLabel(HFrame1121, "c:");
  LabelC -> SetTextJustify(36);
  LabelC -> SetMargins(0, 0, 0, 0);
  LabelC -> SetWrapLength(-1);
  HFrame1121 -> AddFrame(LabelC, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //C Number Entry-----------------------------------------------------------------------------------------
  NumEntC = new TGNumberEntry(HFrame1121, (Double_t) 0, 7, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , 0.0, 2.05);
  HFrame1121 -> AddFrame(NumEntC, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntC -> SetNumber(0.47);
  NumEntC -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupMedPro -> AddFrame(HFrame1121, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));  
  //-------------------------------------------------------------------------------------------------------
  GroupMedPro -> SetLayoutManager(new TGVerticalLayout(GroupMedPro));
  GroupMedPro -> Resize(351, 99);
  VFrame11 -> AddFrame(GroupMedPro, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                    Simulation Parameters Group Frame
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar = new TGGroupFrame(VFrame11, "Simulation Parameters");
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame G & F
  //-------------------------------------------------------------------------------------------------------
  HFrame1131 = new TGHorizontalFrame(GroupSimPar, 315, 29, kHorizontalFrame);
  //g Label------------------------------------------------------------------------------------------------
  LabelG = new TGLabel(HFrame1131, "g[m/s^2]:");
  LabelG -> SetTextJustify(36);
  LabelG -> SetMargins(0, 0, 0, 0);
  LabelG -> SetWrapLength(-1);
  HFrame1131 -> AddFrame(LabelG, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //g Number Entry-----------------------------------------------------------------------------------------
  NumEntG = new TGNumberEntry(HFrame1131, (Double_t) 0, 6, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , 0.0, 24.8);
  HFrame1131 -> AddFrame(NumEntG, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntG -> SetNumber(9.81);
  NumEntG -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //F Label------------------------------------------------------------------------------------------------
  LabelF = new TGLabel(HFrame1131, "F[N]:");
  LabelF -> SetTextJustify(36);
  LabelF -> SetMargins(0, 0, 0, 0);
  LabelF -> SetWrapLength(-1);
  HFrame1131 -> AddFrame(LabelF, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						   kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						   , 2, 2, 2, 2));
  //F Number Entry-----------------------------------------------------------------------------------------
  NumEntF = new TGNumberEntry(HFrame1131, (Double_t) 0, 6, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , 0.0, 1000.0);
  HFrame1131 -> AddFrame(NumEntF, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntF -> SetNumber(5.0);
  NumEntF -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> AddFrame(HFrame1131, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //Horizontal Frame Vectors & Omega
  //-------------------------------------------------------------------------------------------------------
  HFrame1132 = new TGHorizontalFrame(GroupSimPar, 315, 29, kHorizontalFrame);
  //Horizontal Frame Omega---------------------------------------------------------------------------------
  HFrame11321 = new TGHorizontalFrame(HFrame1132, 153, 25, kHorizontalFrame);
  
  //Omega Label--------------------------------------------------------------------------------------------
  LabelOmega_F = new TGLabel(HFrame11321, "w_f[rad/s]:");
  LabelOmega_F -> SetTextJustify(36);
  LabelOmega_F -> SetMargins(0, 0, 0, 0);
  LabelOmega_F -> SetWrapLength(-1);
  HFrame11321 -> AddFrame(LabelOmega_F, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							  , 2, 2, 2, 2));
  //Omega Number Entry-------------------------------------------------------------------------------------
  NumEntOmega_F = new TGNumberEntry(HFrame11321, (Double_t) 0, 6, -1, TGNumberFormat::kNESReal
				    , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				    , 0.0, 100.0);
  HFrame11321 -> AddFrame(NumEntOmega_F, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							   kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntOmega_F -> SetNumber(0.8);
  NumEntOmega_F -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  HFrame1132 -> AddFrame(HFrame11321, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Horizontal Frame Omega---------------------------------------------------------------------------------
  HFrame11322 = new TGHorizontalFrame(HFrame1132, 154, 25, kHorizontalFrame);
  
  //Vectors Check Button-----------------------------------------------------------------------------------
  CheckButtonVectors = new TGCheckButton(HFrame11322, "Show Vectors");
  CheckButtonVectors -> SetTextJustify(36);
  CheckButtonVectors -> SetMargins(0, 0, 0, 0);
  CheckButtonVectors -> SetWrapLength(-1);
  HFrame11322 -> AddFrame(CheckButtonVectors, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
								kLHintsCenterY | kLHintsExpandX |
  								kLHintsExpandY, 2, 2, 2, 2));
  CheckButtonVectors -> SetState(kButtonDown, kTRUE);
  //-------------------------------------------------------------------------------------------------------
  HFrame1132 -> AddFrame(HFrame11322, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> AddFrame(HFrame1132, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupSimPar -> SetLayoutManager(new TGVerticalLayout(GroupSimPar));
  GroupSimPar -> Resize(351, 98);
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
  HFrame1141 = new TGHorizontalFrame(GroupIniCon, 315, 29, kHorizontalFrame);
  //Theta Label--------------------------------------------------------------------------------------------
  LabelTheta = new TGLabel(HFrame1141, "Theta[rad]:");
  LabelTheta -> SetTextJustify(36);
  LabelTheta -> SetMargins(0, 0, 0, 0);
  LabelTheta -> SetWrapLength(-1);
  HFrame1141 -> AddFrame(LabelTheta, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						       , 2, 2, 2, 2));
  //Theta Number Entry-------------------------------------------------------------------------------------
  NumEntTheta = new TGNumberEntry(HFrame1141, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
				  , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				  , -TMath::Pi(), TMath::Pi());
  HFrame1141 -> AddFrame(NumEntTheta, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntTheta -> SetNumber(3.0);
  NumEntTheta -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem();");
  //Omega Label--------------------------------------------------------------------------------------------
  LabelOmega = new TGLabel(HFrame1141, "Omga[rad/s]:");
  LabelOmega -> SetTextJustify(36);
  LabelOmega -> SetMargins(0, 0, 0, 0);
  LabelOmega -> SetWrapLength(-1);
  HFrame1141 -> AddFrame(LabelOmega, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						       kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						       , 2, 2, 2, 2));
  //Omega Number Entry-------------------------------------------------------------------------------------
  NumEntOmega = new TGNumberEntry(HFrame1141, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
				  , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
				  , -99, 99);
  HFrame1141 -> AddFrame(NumEntOmega, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntOmega -> SetNumber(3.0);
  NumEntOmega -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> AddFrame(HFrame1141, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1142 = new TGHorizontalFrame(GroupIniCon, 315, 29, kHorizontalFrame);
  //Horizontal Frame Z-------------------------------------------------------------------------------------
  HFrame11421 = new TGHorizontalFrame(HFrame1142, 154, 25, kHorizontalFrame);
  //Omega Label--------------------------------------------------------------------------------------------
  LabelZ = new TGLabel(HFrame11421, "Z[rad]:");
  LabelZ -> SetTextJustify(36);
  LabelZ -> SetMargins(0, 0, 0, 0);
  LabelZ -> SetWrapLength(-1);
  HFrame11421 -> AddFrame(LabelZ, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						    , 2, 2, 2, 2));
  //Omega Number Entry-------------------------------------------------------------------------------------
  NumEntZ = new TGNumberEntry(HFrame11421, (Double_t) 0, 8, -1, TGNumberFormat::kNESReal
			      , TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax
			      , -TMath::Pi(), TMath::Pi());
  HFrame11421 -> AddFrame(NumEntZ, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						     kLHintsCenterY | kLHintsExpandX, 2, 2, 2, 2));
  NumEntZ -> SetNumber(0.5);
  NumEntZ -> Connect("ValueSet(Long_t)", "WMainPAM", this, "DrawSystem()");
  //-------------------------------------------------------------------------------------------------------
  HFrame1142 -> AddFrame(HFrame11421, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //Horizontal Frame Calculate Button----------------------------------------------------------------------
  HFrame11422 = new TGHorizontalFrame(HFrame1142, 154, 25, kHorizontalFrame);
  //Button Calculate---------------------------------------------------------------------------------------
  TextButtonCalculate = new TGTextButton(HFrame11422, "&Calculate", -1, TGTextButton::GetDefaultGC()()
					 , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonCalculate -> SetTextJustify(36);
  TextButtonCalculate -> SetMargins(0, 0, 0, 0);
  TextButtonCalculate -> SetWrapLength(-1);
  TextButtonCalculate -> Resize(150,26);
  HFrame11422 -> AddFrame(TextButtonCalculate, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  TextButtonCalculate -> Connect("Clicked()", "WMainPAM", this, "TBCalculateSimulCliked()");
  //-------------------------------------------------------------------------------------------------------
  HFrame1142 -> AddFrame(HFrame11422, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> AddFrame(HFrame1142, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
							, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  GroupIniCon -> SetLayoutManager(new TGVerticalLayout(GroupIniCon));
  GroupIniCon -> Resize(351, 99);
  VFrame11 -> AddFrame(GroupIniCon, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						      kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						      , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                         Buttons Horizontal Frame
  //-------------------------------------------------------------------------------------------------------
  HFrame115 = new TGHorizontalFrame(VFrame11, 351, 26, kHorizontalFrame);
  HFrame115 -> SetName("HFrame115");
  //Play Button--------------------------------------------------------------------------------------------
  TextButtonPlay = new TGTextButton(HFrame115, "&Play", -1, TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonPlay -> SetTextJustify(36);
  TextButtonPlay -> SetMargins(0, 0, 0, 0);
  TextButtonPlay -> SetWrapLength(-1);
  TextButtonPlay -> Resize(172, 22);
  HFrame115 -> AddFrame(TextButtonPlay, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsExpandX, 2, 2, 2, 2));
  TextButtonPlay -> Connect("Clicked()", "WMainPAM", this, "TBPlayCliked()");
  
  //Clear Button-------------------------------------------------------------------------------------------
  TextButtonClear = new TGTextButton(HFrame115, "&Clear", -1, TGTextButton::GetDefaultGC()()
				     , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonClear -> SetTextJustify(36);
  TextButtonClear -> SetMargins(0, 0, 0, 0);
  TextButtonClear -> SetWrapLength(-1);
  TextButtonClear -> Resize(172, 22);
  HFrame115 -> AddFrame(TextButtonClear, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							   kLHintsExpandX, 2, 2, 2, 2));
  TextButtonClear -> Connect("Clicked()", "WMainPAM", this, "TBClearCliked()");
  //Exit Button--------------------------------------------------------------------------------------------
  TextButtonExit = new TGTextButton(HFrame115, "&Exit", -1, TGTextButton::GetDefaultGC()()
				    , TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
  TextButtonExit -> SetTextJustify(36);
  TextButtonExit -> SetMargins(0, 0, 0, 0);
  TextButtonExit -> SetWrapLength(-1);
  TextButtonExit -> Resize(172, 22);
  HFrame115 -> AddFrame(TextButtonExit, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
							  kLHintsExpandX, 2, 2, 2, 2));
  TextButtonExit -> Connect("Clicked()", "WMainPAM", this, "TBExitCliked()");
  //-------------------------------------------------------------------------------------------------------
  VFrame11 -> AddFrame(HFrame115, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						    kLHintsExpandX, 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  HFrame1 -> AddFrame(VFrame11, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |
						  kLHintsCenterY | kLHintsExpandX | kLHintsExpandY
						  , 2, 2, 2, 2));
  //=======================================================================================================
  //                                           Vertical Frame I, II
  //=======================================================================================================
  VFrame12 = new TGVerticalFrame(HFrame1, 355, 440, kVerticalFrame);
  VFrame12 -> SetName("VFrame12");
  //-------------------------------------------------------------------------------------------------------
  //                                             Simulation Canvas
  //-------------------------------------------------------------------------------------------------------
  EmbeddedSimulCanvas = new TRootEmbeddedCanvas(0, VFrame12, 352, 436, kSunkenFrame);
  EmbeddedSimulCanvas -> SetName("EmbeddedSimulCanvas");
  Int_t wEmbeddedSimulCanvas = EmbeddedSimulCanvas -> GetCanvasWindowId();
  CanvasSimul = new TCanvas("CanvasSimul", 10, 10, wEmbeddedSimulCanvas);
  // EmbeddedSimulCanvas -> AdoptCanvas(CanvasSimul);
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
  //                                                Tabs I - IV
  //=======================================================================================================
  Tabs = new TGTab(HFrame1, 355, 440);
  //-------------------------------------------------------------------------------------------------------
  //                                             Container of Tab1
  //-------------------------------------------------------------------------------------------------------
  CompFrame121 = Tabs -> AddTab("Phase space");
  CompFrame121 -> SetLayoutManager(new TGVerticalLayout(CompFrame121));
  
  EmbeddedFaseCanvas = new TRootEmbeddedCanvas(0, CompFrame121, 348, 411, kSunkenFrame);
  Int_t wEmbeddedFaseCanvas = EmbeddedFaseCanvas -> GetCanvasWindowId();
  CanvasFase = new TCanvas("CanvasFase", 10, 10, wEmbeddedFaseCanvas);
  CanvasFase -> ToggleEditor();
  CanvasFase -> SetFillColor(kWhite);
  CanvasFase -> SetGrid();
  //TGraphPhase = new TGraph();
  
  EmbeddedFaseCanvas -> AdoptCanvas(CanvasFase);
  CompFrame121 -> AddFrame(EmbeddedFaseCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                             Container of Tab2
  //-------------------------------------------------------------------------------------------------------
  CompFrame122 = Tabs -> AddTab("Poincar\351 map");
  CompFrame122 -> SetLayoutManager(new TGVerticalLayout(CompFrame122));
  
  EmbeddedPoinCanvas = new TRootEmbeddedCanvas(0, CompFrame122, 348, 411, kSunkenFrame);
  Int_t wEmbeddedPoinCanvas = EmbeddedPoinCanvas -> GetCanvasWindowId();
  CanvasPoin = new TCanvas("CanvasPoin", 10, 10, wEmbeddedPoinCanvas);
  CanvasPoin -> ToggleEditor();
  CanvasPoin -> SetFillColor(kWhite);
  CanvasPoin -> SetGrid();
  //TGraphPoincare = new TGraph();
  
  EmbeddedPoinCanvas -> AdoptCanvas(CanvasPoin);
  CompFrame122 -> AddFrame(EmbeddedPoinCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								 kLHintsTop | kLHintsCenterY |
								 kLHintsExpandX | kLHintsExpandY
								 , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  //                                             Container of Tab3
  //-------------------------------------------------------------------------------------------------------
  CompFrame123 = Tabs -> AddTab("Lyapunov");
  CompFrame123 -> SetLayoutManager(new TGVerticalLayout(CompFrame123));
  
  EmbeddedLyapuCanvas = new TRootEmbeddedCanvas(0, CompFrame123, 348, 411, kSunkenFrame);
  Int_t wEmbeddedLyapuCanvas = EmbeddedLyapuCanvas -> GetCanvasWindowId();
  CanvasLyapu = new TCanvas("CanvasLyapu", 10, 10, wEmbeddedLyapuCanvas);
  CanvasLyapu -> ToggleEditor();
  CanvasLyapu -> SetFillColor(kWhite);
  CanvasLyapu -> SetGrid();
  TGraphLyapunov = new TGraph();
  
  EmbeddedLyapuCanvas -> AdoptCanvas(CanvasLyapu);
  CompFrame123 -> AddFrame(EmbeddedLyapuCanvas, new TGLayoutHints(kLHintsLeft | kLHintsCenterX |
								  kLHintsTop | kLHintsCenterY |
								  kLHintsExpandX | kLHintsExpandY
								  , 2, 2, 2, 2));
  //-------------------------------------------------------------------------------------------------------
  Tabs -> SetTab(0);
  Tabs -> Resize(Tabs -> GetDefaultSize());
  HFrame1 -> AddFrame(Tabs, new TGLayoutHints(kLHintsLeft | kLHintsCenterX | kLHintsTop |kLHintsCenterY |
					      kLHintsExpandX | kLHintsExpandY, 2, 2, 2, 2));
  //=======================================================================================================
  MainFrame -> AddFrame(HFrame1, new TGLayoutHints(kLHintsCenterX |kLHintsCenterY | kLHintsExpandX |
						   kLHintsExpandY, 1, 1, 1, 1));
  
  MainFrame -> SetMWMHints(kMWMDecorAll, kMWMFuncAll, kMWMInputModeless);
  MainFrame -> MapSubwindows();
  MainFrame -> Resize(MainFrame -> GetDefaultSize());
  MainFrame -> Resize(1081, 446);
  MainFrame -> MapWindow();
  //=======================================================================================================
  Cont = new TTimer(100);
  Cont -> Connect("Timeout()", "WMainPAM", this, "DoDraw()");
  IsActive = -1;
}

void WMainPAM::ResizeSimulCanvas(){
  CanvasSimul -> Range(-1.5*(GetLength() + GetRadius()), -1.5*(GetLength() + GetRadius()),
		         1.5*(GetLength() + GetRadius()), 1.5*(GetLength() + GetRadius()));
}

void WMainPAM::DrawSystem(){
  ResizeSimulCanvas();

  Box = new TBox();
  Box -> SetFillColor(28);
  
  Rope = new TLine();
  Rope -> SetLineColor(1);
  Rope -> SetX1(0.);
  Rope -> SetY1(0.);
  
  Lentil = new TEllipse();
  Lentil -> SetFillColor(6);
  Lentil -> SetPhimin(0.);
  Lentil -> SetPhimax(360.);

  Rope -> SetX2((GetLength())*TMath::Sin(GetTheta()));
  Rope -> SetY2(-(GetLength())*TMath::Cos(GetTheta()));
  
  Lentil -> SetR1(GetRadius());
  Lentil -> SetR2(GetRadius());

  Lentil -> SetX1((GetLength())*TMath::Sin(GetTheta()));
  Lentil -> SetY1(-(GetLength())*TMath::Cos(GetTheta()));
  
  Box -> SetX1(-(GetLength())/2.);
  Box -> SetY1((GetRadius())/2.);
  Box -> SetX2((GetLength())/2.);
  Box -> SetY2(-(GetRadius())/2.);

  CanvasSimul -> cd();

  DrawBeforeVectors();

  Box ->Draw();
  Rope -> Draw();
  Lentil -> Draw();
  ArrowPush -> Draw();
  ArrowWeight -> Draw();
  ArrowDrag -> Draw();
  ArrowForcing -> Draw();

  CanvasSimul -> Modified();
  CanvasSimul -> Update();

  delete Box;
  delete Rope;
  delete Lentil;
  delete ArrowPush;
  delete ArrowWeight;
  delete ArrowDrag;
  delete ArrowForcing;
}

void WMainPAM::DrawBeforeVectors(){

  ArrowPush = new TArrow();
  ArrowPush -> SetLineColor(2);
  ArrowPush -> SetFillColor(2);
  ArrowPush -> SetLineWidth(1);
  
  ArrowDrag = new TArrow();
  ArrowDrag -> SetLineColor(3);
  ArrowDrag -> SetFillColor(3);
  ArrowDrag -> SetLineWidth(2);
  
  ArrowWeight = new TArrow();
  ArrowWeight -> SetLineColor(4);
  ArrowWeight -> SetFillColor(4);
  ArrowWeight -> SetLineWidth(1);
  
  ArrowForcing = new TArrow();
  ArrowForcing -> SetLineColor(5);
  ArrowForcing -> SetFillColor(5);
  ArrowForcing -> SetLineWidth(1);
  //=======================================================================================================
  if(CheckButtonVectors -> IsDown()){
    
    ArrowPush -> SetX1(GetLength()*TMath::Sin(GetTheta()));
    ArrowPush -> SetY1(-GetLength()*TMath::Cos(GetTheta()));
    ArrowPush -> SetX2(GetLength()*TMath::Sin(GetTheta()));
    ArrowPush -> SetY2(-GetLength()*TMath::Cos(GetTheta()) +
		       0.1*(GetRho())*(3./4.)*TMath::Pi()*TMath::Power(GetRadius(), 3.)*GetG());
    
    if((TMath::Abs(GetLength()*TMath::Sin(GetTheta())) <= 1.5*(GetLength() + GetRadius())) ||
       (TMath::Abs(-GetLength()*TMath::Cos(GetTheta()) +
		   0.1*(GetRho())*(3./4.)*TMath::Pi()*TMath::Power(GetRadius(), 3.)*GetG()) <=
	1.5*(GetLength() + GetRadius()))){
      ArrowPush -> SetArrowSize(0.02); ArrowPush -> SetOption("|>");
    }
    else{
      ArrowPush -> SetOption("");
    }
    
    ArrowWeight -> SetX1(GetLength()*TMath::Sin(GetTheta()));
    ArrowWeight -> SetY1(-GetLength()*TMath::Cos(GetTheta()));
    ArrowWeight -> SetX2(GetLength()*TMath::Sin(GetTheta()));
    ArrowWeight -> SetY2(-GetLength()*TMath::Cos(GetTheta()) - 0.1*GetMass()*GetG());
    
    if((TMath::Abs(GetLength()*TMath::Sin(GetTheta())) <= 1.5*(GetLength() + GetRadius())) ||
       (TMath::Abs(-GetLength()*TMath::Cos(GetTheta()) - 0.1*GetMass()*GetG()) <=
	1.5*(GetLength() + GetRadius()))){
      ArrowWeight -> SetArrowSize(0.02); ArrowWeight -> SetOption("|>");
    }
    else{ 
      ArrowWeight -> SetOption("");
    }
    
    ArrowDrag -> SetX1(GetLength()*TMath::Sin(GetTheta()));
    ArrowDrag -> SetY1(-GetLength()*TMath::Cos(GetTheta()));
    ArrowDrag -> SetX2(GetLength()*TMath::Sin(GetTheta()) - 0.05*GetC()*GetRho()*TMath::Pi()*
		       TMath::Power(GetRadius(), 2.)*TMath::Power(GetLength(), 2.)*TMath::Cos(GetTheta())*
		       TMath::Abs(GetOmega())*GetOmega());
    ArrowDrag -> SetY2(-GetLength()*TMath::Cos(GetTheta()) - 0.05*GetC()*GetRho()*TMath::Pi()*
		       TMath::Power(GetRadius(), 2.)*TMath::Power(GetLength(), 2.)*TMath::Sin(GetTheta())*
		       TMath::Abs(GetOmega())*GetOmega());
    
    if((TMath::Abs(GetLength()*TMath::Sin(GetTheta()) - 0.05*GetC()*GetRho()*TMath::Pi()*
		   TMath::Power(GetRadius(), 2.)*TMath::Power(GetLength(), 2.)*TMath::Cos(GetTheta())*
		   TMath::Abs(GetOmega())*GetOmega()) <= 1.5*(GetLength() + GetRadius())) ||
       (TMath::Abs(-GetLength()*TMath::Cos(GetTheta()) - 0.05*GetC()*GetRho()*TMath::Pi()*
		   TMath::Power(GetRadius(), 2.)*TMath::Power(GetLength(), 2.)*TMath::Sin(GetTheta())*
		   TMath::Abs(GetOmega())*GetOmega()) <= 1.5*(GetLength() + GetRadius()))){
      ArrowDrag -> SetArrowSize(0.02); ArrowDrag -> SetOption("|>");
    }
    else{
      ArrowDrag -> SetOption("");
    }
    
    ArrowForcing -> SetX1(GetLength()*TMath::Sin(GetTheta()));
    ArrowForcing -> SetY1(-GetLength()*TMath::Cos(GetTheta()));
    ArrowForcing -> SetX2(GetLength()*TMath::Sin(GetTheta()) +
			  0.1*GetF()*TMath::Sin(GetZ())*TMath::Cos(GetTheta()));
    ArrowForcing -> SetY2(-GetLength()*TMath::Cos(GetTheta()) +
			  0.1*GetF()*TMath::Sin(GetZ())*TMath::Sin(GetTheta()));
    
    if((TMath::Abs(GetLength()*TMath::Sin(GetTheta()) +
		   0.1*GetF()*TMath::Sin(GetZ())*TMath::Cos(GetTheta())) <=
	1.5*(GetLength() + GetRadius())) ||
       (TMath::Abs(-GetLength()*TMath::Cos(GetTheta()) +
		   0.1*GetF()*TMath::Sin(GetZ())*TMath::Sin(GetTheta())) <=
	1.5*(GetLength() + GetRadius()))){
      ArrowForcing -> SetArrowSize(0.02); ArrowForcing -> SetOption("|>");
    }
    else{
      ArrowForcing -> SetOption("");
    }
    
  }
  if(!CheckButtonVectors -> IsDown()){
    ArrowPush -> SetX1(0.0); ArrowPush -> SetY1(0.0);
    ArrowPush -> SetX2(0.0); ArrowPush -> SetY2(0.0);
    
    ArrowWeight -> SetX1(0.0); ArrowWeight -> SetY1(0.0);
    ArrowWeight -> SetX2(0.0); ArrowWeight -> SetY2(0.0);
    
    ArrowDrag -> SetX1(0.0); ArrowDrag -> SetY1(0.0);
    ArrowDrag -> SetX2(0.0); ArrowDrag -> SetY2(0.0);
    
    ArrowForcing -> SetX1(0.0); ArrowForcing -> SetY1(0.0);
    ArrowForcing -> SetX2(0.0); ArrowForcing -> SetY2(0.0);
    
  }
}

void WMainPAM::TBCalculateSimulCliked(){
  //t0 = clock();
  CanvasSimul -> cd();
  TText *text = new TText(0.0,0.0,"Estimating...");
  text -> SetTextAlign(22);
  text -> SetTextSize(0.05);
  text -> Draw();
  CanvasSimul -> Update();
  
  outfile.open("/tmp/Pendulo.m");
  
  Omega_F = GetOmega_F();
  Omega   = GetOmega();
  Theta   = GetTheta();
  L       = GetLength();
  R       = GetRadius();
  M       = GetMass();
  Rho     = GetRho();
  C       = GetC();
  F       = GetF();
  G       = GetG();
  Z       = GetZ();
  
  I = M*(TMath::Power(L, 2.) + (2./5.)*TMath::Power(R, 2.));
  
  Alpha = (((4./3.)*Rho*TMath::Pi()*TMath::Power(R, 3.) - M)*G*L)/I;
  Beta  = ((1./2.)*C*Rho*TMath::Pi()*TMath::Power(R, 2.)*TMath::Power(L, 3.))/I;
  Gamma = (F*L)/I;

  //=======================================================================================================
  //OCTAVE SCRIPT 
  //=======================================================================================================
  outfile << "## Solve Differential Equation" << endl;
  //outfile << "tic;" << endl;
  outfile << "x = 0.;" << endl;
  outfile << "t = 0.;" << endl;
  outfile << "function xdot=f(x,t)" << endl;
  outfile << "  xdot(1)=-" << setprecision(15) << Beta << "*x(1)*abs(x(1))+"
	  << setprecision(15) << Alpha << "*sin(x(2))+"
	  << setprecision(15) << Gamma << "*sin(x(3));" << endl;
  outfile << "  xdot(2)=x(1);" << endl;
  outfile << "  xdot(3)=" << setprecision(15) << Omega_F << ";" << endl;
  outfile << "endfunction" << endl;
  outfile << "x=lsode('f',[" << setprecision(15) << Omega << ";" << setprecision(15) << Theta
	  << ";" << Z << "],(t=linspace(0," << setprecision(15)
	  << (2.0*TMath::Pi()/Omega_F)*1000. << "," << 1000000 << ")'));" << endl;
  outfile << "M=[t,x];" << endl;
  outfile << "dlmwrite('/tmp/pendulo.dat',M,'\t');" << endl;
  //outfile << "toc;" << endl;
  outfile.close();
  
  system("octave -q /tmp/Pendulo.m");

  delete text;
  DrawSystem();
  infile.open("/tmp/pendulo.dat");

  //t1 = clock();
  //double time_med = (double(t1-t0)/CLOCKS_PER_SEC);
  //cout << "execution time: " << time_med << endl;
}

void WMainPAM::Disable(){
  TextButtonClear -> SetEnabled(kFALSE);
  NumEntMass -> SetState(kFALSE);
  NumEntLength -> SetState(kFALSE);
  NumEntRadius -> SetState(kFALSE);
  NumEntRho -> SetState(kFALSE);
  NumEntC -> SetState(kFALSE);
  NumEntG -> SetState(kFALSE);
  NumEntF -> SetState(kFALSE);
  NumEntOmega_F -> SetState(kFALSE);
  NumEntOmega -> SetState(kFALSE);
  NumEntTheta -> SetState(kFALSE);
  NumEntZ -> SetState(kFALSE);
}

void WMainPAM::Enable(){
  TextButtonClear -> SetEnabled(kTRUE);
  NumEntMass -> SetState(kTRUE);
  NumEntLength -> SetState(kTRUE);
  NumEntRadius -> SetState(kTRUE);
  NumEntRho -> SetState(kTRUE);
  NumEntC -> SetState(kTRUE);
  NumEntG -> SetState(kTRUE);
  NumEntF -> SetState(kTRUE);
  NumEntOmega_F -> SetState(kTRUE);
  NumEntOmega -> SetState(kTRUE);
  NumEntTheta -> SetState(kTRUE);
  NumEntZ -> SetState(kTRUE);
}

void WMainPAM::TBPlayCliked(){
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

void WMainPAM::TBClearCliked(){
  
  Enable();
  infile.close();
  
  i = 0; k = 0; n = 0;
  SeigenvalOmega  = 0.;
  SeigenvalTheta  = 0.;
  
  for(j = 0; j <= 199; j ++){

    Omega_Matrix[j] = 0.0;
    Theta_Matrix[j] = 0.0;

    Omega_M_Poin[j] = 0.0; Omega_M_Poin[j + 200] = 0.0;
    Omega_M_Poin[j + 400] = 0.0; Omega_M_Poin[j + 600] = 0.0;
    Omega_M_Poin[j + 800] = 0.0;

    Theta_M_Poin[j] = 0.0; Theta_M_Poin[j + 200] = 0.0;
    Theta_M_Poin[j + 400] = 0.0; Theta_M_Poin[j + 600] = 0.0;
    Theta_M_Poin[j + 800] = 0.0;

    T[j]      = 0.;
    LOmega[j] = 0.;
    LTheta[j] = 0.;
    LZ[j]     = 0.;
  }

  j = 0;
  IsActive = -1;
}

void WMainPAM::DoDraw(){
  for(k = 0; k < 10; k ++){
    n++;
    
    infile >> Time;
    infile >> Omega;
    infile >> Theta;
    infile >> Z;
    
    I = GetMass()*(TMath::Power(GetLength(), 2.) + (2./5.)*TMath::Power(GetRadius(), 2.));
    
    Alpha = (((4./3.)*GetRho()*TMath::Pi()*TMath::Power(R, 3.) - GetMass())*GetG()*GetLength());
    Beta  = ((1./2.)*GetC()*GetRho()*TMath::Pi()*TMath::Power(GetRadius(), 2.)
	     *TMath::Power(GetLength(), 3.));
    Gamma = (GetF()*GetLength());
    //=======================================================================================================
    // JACOBIAN MATRIX
    //=======================================================================================================
    TMatrixD J(3, 3);
    J(0, 0) = -2.*Beta*TMath::Abs(Omega); J(0, 1) = Alpha*TMath::Cos(Theta); J(0, 2) = Gamma*TMath::Cos(Z);
    J(1, 0) = 1./I;                         J(1, 1) = 0.;                      J(1, 2) = 0.;
    J(2, 0) = 0.;                         J(2, 1) = 0.;                      J(2, 2) = 0.;
    //-------------------------------------------------------------------------------------------------------
    //CALCULATION OF OWN VALUES
    //-------------------------------------------------------------------------------------------------------
    TMatrixDEigen me(J);
    TVectorD eigenval = me.GetEigenValuesRe();
    
    SeigenvalOmega   += eigenval(0);
    SeigenvalTheta   += eigenval(1);
    SeigenvalZ       += eigenval(2);
    //-------------------------------------------------------------------------------------------------------
    //AVERAGE
    //-------------------------------------------------------------------------------------------------------
    MeigenvalOmega   = SeigenvalOmega/(Double_t)n;
    MeigenvalTheta   = SeigenvalTheta/(Double_t)n;
    MeigenvalZ       = SeigenvalZ/(Double_t)n;
  }
  
  NumEntOmega -> SetNumber(Omega);
  
  NumEntTheta -> SetNumber(TMath::ATan2(TMath::Sin(Theta), TMath::Cos(Theta)));
  NumEntZ -> SetNumber(Z);
  
  Omega_Matrix[j%200] = Omega;
  Theta_Matrix[j%200] = TMath::ATan2(TMath::Sin(Theta), TMath::Cos(Theta));
  
  
  T[j%200]      = Time;
  LOmega[j%200] = MeigenvalOmega;
  LTheta[j%200] = MeigenvalTheta;
  LZ[j%200]     = MeigenvalZ;
  j ++;
  
  CanvasFase -> cd();  

  TGraphPhase = new TGraph(200, Theta_Matrix, Omega_Matrix);
  TGraphPhase -> SetTitle("Phase");
  TGraphPhase -> SetMarkerColor(2);
  TGraphPhase -> SetMarkerStyle(20);
  TGraphPhase -> SetMarkerSize(0.5);
 
  TGraphPhase -> GetXaxis() -> SetRangeUser(-4.0,4.0);
  TGraphPhase -> GetXaxis() -> SetTitle("#theta");
  TGraphPhase -> GetYaxis() -> SetTitle("#omega");
  TGraphPhase -> GetXaxis() -> SetLabelSize(0.05);
  TGraphPhase -> GetYaxis() -> SetLabelSize(0.05);

  TGraphPhase -> Draw("AP");
  CanvasFase -> Modified();
  CanvasFase -> Update();
  delete TGraphPhase;
  
  if(j%100==0){
    Omega_M_Poin[i] = Omega;;
    Theta_M_Poin[i] = TMath::ATan2(TMath::Sin(Theta), TMath::Cos(Theta));
    i ++;
  }
  CanvasPoin -> cd();
  TGraphPoincare = new TGraph(1000, Theta_M_Poin, Omega_M_Poin);
  TGraphPoincare -> SetTitle("Poincar\351");
  TGraphPoincare -> SetMarkerColor(4);
  TGraphPoincare -> SetMarkerStyle(20);
  TGraphPoincare -> SetMarkerSize(0.5);
  TGraphPoincare -> GetXaxis()->SetRangeUser(-4.0,4.0);
  TGraphPoincare -> GetXaxis()->SetTitle("#theta");
  TGraphPoincare -> GetYaxis()->SetTitle("#omega");
  TGraphPoincare -> GetXaxis() -> SetLabelSize(0.05);
  TGraphPoincare -> GetYaxis() -> SetLabelSize(0.05);
  TGraphPoincare ->Draw("AP");
  CanvasPoin -> Modified();
  CanvasPoin -> Update();
  delete TGraphPoincare;
    
  CanvasLyapu -> cd();
  Exponentes = new TMultiGraph();
  Exponentes -> SetTitle("Lyapunov");
  Exponentes -> GetXaxis() -> SetTitle("t(s)");
  Exponentes -> GetYaxis() -> SetTitle("#lambda");
  Exponentes -> GetXaxis() -> SetLabelSize(0.05);
  Exponentes -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL1 = new TGraph(200, T, LOmega);
  TGraphL1 -> SetTitle("#lambda_{L}");
  TGraphL1 -> SetMarkerColor(4);
  TGraphL1 -> SetMarkerStyle(20);
  TGraphL1 -> SetMarkerSize(0.5);
  TGraphL1 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL1 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL2 = new TGraph(200, T, LTheta);
  TGraphL2 -> SetTitle("#lambda_{#theta}");
  TGraphL2 -> SetMarkerColor(5);
  TGraphL2 -> SetMarkerStyle(20);
  TGraphL2 -> SetMarkerSize(0.5);
  TGraphL2 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL2 -> GetYaxis() -> SetLabelSize(0.05);

  TGraphL3 = new TGraph(200, T, LZ);
  TGraphL3 -> SetTitle("#lambda_{z}");
  TGraphL3 -> SetMarkerColor(6);
  TGraphL3 -> SetMarkerStyle(20);
  TGraphL3 -> SetMarkerSize(0.5);
  TGraphL3 -> GetXaxis() -> SetLabelSize(0.05);
  TGraphL3 -> GetYaxis() -> SetLabelSize(0.05);

  Exponentes -> Add(TGraphL1);
  Exponentes -> Add(TGraphL2);
  Exponentes -> Add(TGraphL3);

  Exponentes -> Draw("ap");
  CanvasLyapu -> BuildLegend();
  CanvasLyapu -> Modified();
  CanvasLyapu -> Update();
    
  delete TGraphL1;
  delete TGraphL2;
  delete TGraphL3;
  delete Exponentes;
  
  DrawSystem(); 
}

void WMainPAM::TBExitCliked(){
  //-------------------------------------------------------------------------------------------------------
  // Stop the simulation and close Window
  //-------------------------------------------------------------------------------------------------------
  Cont -> TurnOff();
  MainFrame -> CloseWindow();
  //gApplication -> Terminate(0);
}

WMainPAM::~WMainPAM(){
  MainFrame -> Cleanup();
  delete MainFrame;
}
