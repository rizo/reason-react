[@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";

type error = {. };

[@bs.module "react-dom/server"]
external renderToPipeableStream: (
  ~bootstrapScriptContent: string,
  ~bootstrapScripts: array(string),
  ~bootstrapModules: array(string),
  ~identifierPrefix: string,
  ~namespaceURI: string,
  ~nonce: string,
  ~onAllReady: unit => unit,
  ~onError: error => unit,
  ~onShellReady: unit => unit,
  ~onShellError: error => unit,
  ~progressiveChunkSize: int,
  React.element) => string =
  "renderToPipeableStream";
