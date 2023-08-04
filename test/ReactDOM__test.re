open Jest;
open Jest.Expect;

module Stream = {
  type writable;

  [@bs.send]
  external setEncoding: (writable, string) => unit = "setEncoding";

  [@bs.send]
  external on: (writable, string, string => unit) => unit = "on";

  [@bs.module "stream"] [@bs.new]
  external make: unit => writable = "PassThrough";
}

describe("ReactDOM", () => {
  describe("ReactDOMServer", () => {
    test("renderToString", () => {
      let string = ReactDOMServer.renderToString(<div> "Hello world!"->React.string </div>);
      expect(string)->toBe("<div>Hello world!</div>");
    });
    test("renderToStaticMarkup", () => {
      let string = ReactDOMServer.renderToStaticMarkup(<div> "Hello world!"->React.string </div>);
      expect(string)->toBe("<div>Hello world!</div>");
    });

    testAsync("renderToPipeableStream", (finish) => {
      let buffer = ref("");
      let hasErrored = ref(false);
      let stream = Stream.make();
      Stream.setEncoding(stream, "utf8");
      Stream.on(stream, "data", (data) => {
        buffer := buffer.contents ++ data;
        expect(buffer.contents)->toBe("<div>Hello world!</div>");
        expect(hasErrored.contents)->toBe(false);

        finish();
      });
      Stream.on(stream, "error", (error) => {
        buffer := buffer.contents ++ error;
        hasErrored := true;
      });
      let ({ pipe, abort:_ }: ReactDOM.Server.pipeableStream) = ReactDOMServer.renderToPipeableStream(<div> "Hello world!"->React.string </div>);
      /* Since we bind to {. } in ReactDOM.Server.pipeableStream, we need to cast */
      let streamAsObject: {.} = Obj.magic(stream);
      pipe(streamAsObject);
    });
  });
});
