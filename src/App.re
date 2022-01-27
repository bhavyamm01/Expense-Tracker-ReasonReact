[%bs.raw {|require('./App.css')|}];

open Dom_storage2;

[@react.component]
let make = () => {
  let retrievedItem = localStorage->getItem("key");

  let parsingFunction = item => {
    switch (item) {
    | Some(result) => Js.Json.parseExn(result)
    | None => Js.Json.string("")
    };
  };

  let convertor = (json: Js.Json.t): Transactions.t => {
    Json.Decode.{
      amount: json |> field("amount", int),
      comment: json |> field("comment", string),
    };
  };

  let execute = (json: Js.Json.t): array(Transactions.t) => {
    Json.Decode.(json |> array(convertor));
  };

  let decodedData = retrievedItem |> parsingFunction |> execute;

  Js.log2(decodedData, "decodeData")

  let (transactions, setTransactions) =
    React.useState(_ => decodedData != [||] ? decodedData : [||]);

  let addTransaction = transaction => {
    setTransactions(_ => Array.concat([[|transaction|], transactions])); // concat or append

    let stringifiedData =
      Js.Json.stringifyAny(
        Array.concat([
          [|transaction|],
          transactions
        ]),
      );

    switch (stringifiedData) {
    | Some(result) => localStorage->setItem("key", result)
    | None => ()
    };
  };

  <div className="container">
    <h2> {React.string("Expense Tracker")} </h2>
    <Amount transactions />
    <History transactions />
    <AddNewTransaction addTransaction />
  </div>;
};
