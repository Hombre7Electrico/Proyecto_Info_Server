object Form1: TForm1
  Left = 301
  Top = 227
  Width = 928
  Height = 414
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 264
    Top = 40
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 264
    Top = 64
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object Label3: TLabel
    Left = 264
    Top = 88
    Width = 32
    Height = 13
    Caption = 'Label3'
  end
  object Label4: TLabel
    Left = 264
    Top = 112
    Width = 32
    Height = 13
    Caption = 'Label4'
  end
  object Label5: TLabel
    Left = 264
    Top = 136
    Width = 32
    Height = 13
    Caption = 'Label5'
  end
  object Label6: TLabel
    Left = 264
    Top = 160
    Width = 32
    Height = 13
    Caption = 'Label6'
  end
  object Label7: TLabel
    Left = 8
    Top = 40
    Width = 101
    Height = 13
    Caption = 'pH AGUA TRATADA'
  end
  object Label8: TLabel
    Left = 8
    Top = 64
    Width = 212
    Height = 13
    Caption = 'TEMPERATURA PREPARACI'#211'N J SIMPLE'
  end
  object Label9: TLabel
    Left = 8
    Top = 88
    Width = 158
    Height = 13
    Caption = 'TEMPERATURA J TERMINADO'
  end
  object Label10: TLabel
    Left = 8
    Top = 112
    Width = 189
    Height = 13
    Caption = 'PRESI'#211'N TANQUE CARBONATADOR'
  end
  object Label11: TLabel
    Left = 8
    Top = 136
    Width = 122
    Height = 13
    Caption = 'pH BEBIDA GASIFICADA'
  end
  object DdeServerItem1: TDdeServerItem
    Left = 376
    Top = 32
  end
  object DdeServerItem2: TDdeServerItem
    Left = 376
    Top = 64
  end
  object DdeServerItem3: TDdeServerItem
    Left = 376
    Top = 96
  end
  object DdeServerItem4: TDdeServerItem
    Left = 376
    Top = 128
  end
  object DdeServerItem5: TDdeServerItem
    Left = 376
    Top = 160
  end
  object DdeServerConv1: TDdeServerConv
    Left = 8
    Top = 160
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 416
    Top = 32
  end
  object Timer2: TTimer
    Interval = 200
    OnTimer = Timer2Timer
    Left = 416
    Top = 64
  end
  object Timer3: TTimer
    Interval = 200
    OnTimer = Timer3Timer
    Left = 416
    Top = 96
  end
  object Timer4: TTimer
    Interval = 200
    OnTimer = Timer4Timer
    Left = 416
    Top = 128
  end
  object Timer5: TTimer
    Interval = 200
    OnTimer = Timer5Timer
    Left = 416
    Top = 160
  end
end
