unit uServerStatus;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls;

type
  TServerStatus = class(TForm)
    OKBtn: TButton;
    StartTime: TEdit;
    CurrentTime: TEdit;
    LastUpdate: TEdit;
    ServerState: TEdit;
    GroupCount: TEdit;
    BandWidth: TEdit;
    MajorVersion: TEdit;
    MinorVersion: TEdit;
    BuildVersion: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  ServerStatus: TServerStatus;

implementation

{$R *.dfm}

end.
