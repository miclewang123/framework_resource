unit uGroupStatus;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls;

type
  TGroupStatus = class(TForm)
    Button1: TButton;
    Button2: TButton;
    Name: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    UpdateRate: TEdit;
    Label3: TLabel;
    TimeBias: TEdit;
    Label4: TLabel;
    Active: TCheckBox;
    DeadBand: TEdit;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  GroupStatus: TGroupStatus;

implementation

{$R *.dfm}

end.
