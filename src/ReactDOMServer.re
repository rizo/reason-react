[@bs.module "react-dom/server"]
external renderToString: React.element => string = "renderToString";

[@bs.module "react-dom/server"]
external renderToStaticMarkup: React.element => string =
  "renderToStaticMarkup";

type error = {.};

[@deriving abstract]
type options = {
  [@bs.optional]
  bootstrapScriptContent: option(string),
  [@bs.optional]
  bootstrapScripts: option(array(string)),
  [@bs.optional]
  bootstrapModules: option(array(string)),
  [@bs.optional]
  identifierPrefix: option(string),
  [@bs.optional]
  namespaceURI: option(string),
  [@bs.optional]
  nonce: option(string),
  [@bs.optional]
  onAllReady: option(unit => unit),
  [@bs.optional]
  onError: option(error => unit),
  [@bs.optional]
  onShellReady: option(unit => unit),
  [@bs.optional]
  onShellError: option(error => unit),
  [@bs.optional]
  progressiveChunkSize: option(int),
};

[@bs.module "react-dom/server"]
external renderToPipeableStream: (React.element, options) => string =
  "renderToPipeableStream";

let renderToPipeableStream =
    (
      ~bootstrapScriptContent,
      ~bootstrapScripts,
      ~bootstrapModules,
      ~identifierPrefix,
      ~namespaceURI,
      ~nonce,
      ~onAllReady,
      ~onError,
      ~onShellReady,
      ~onShellError,
      ~progressiveChunkSize,
      element,
    ) =>
  renderToPipeableStream(
    element,
    options(
      ~bootstrapScriptContent,
      ~bootstrapScripts,
      ~bootstrapModules,
      ~identifierPrefix,
      ~namespaceURI,
      ~nonce,
      ~onAllReady,
      ~onError,
      ~onShellReady,
      ~onShellError,
      ~progressiveChunkSize,
      (),
    ),
  );
