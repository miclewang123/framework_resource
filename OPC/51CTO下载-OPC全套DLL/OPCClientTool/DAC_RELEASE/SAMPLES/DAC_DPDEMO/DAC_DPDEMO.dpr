program DAC_DPDEMO;

uses
  Forms,
  uMain in 'uMain.pas' {Form1},
  DACLTSDK in 'DACLTSDK.pas',
  uGroupStatus in 'uGroupStatus.pas' {GroupStatus},
  uServerBrowser in 'uServerBrowser.pas' {ServerBrowser},
  uItemBrowser in 'uItemBrowser.pas' {ItemBrowser},
  uServerStatus in 'uServerStatus.pas' {ServerStatus},
  uItemStatus in 'uItemStatus.pas' {ItemStatus};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
