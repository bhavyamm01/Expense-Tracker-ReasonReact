module TransactionsStore = {
  let fetchTransactions = () => {
    let retrievedItem =
      Dom_storage2.localStorage->Dom_storage2.getItem("transactions");

    let parsingFunction = item => {
      switch (item) {
      | Some(result) => Js.Json.parseExn(result)
      | None => Js.Json.string("")
      };
    };

    let convertor = (json: Js.Json.t): Transaction.t => {
      Json.Decode.{
        amount: json |> field("amount", int),
        comment: json |> field("comment", string),
      };
    };

    let execute = (json: Js.Json.t): array(Transaction.t) =>
      if (json === Js.Json.string("")) {
        [||];
      } else {
        Json.Decode.(json |> array(convertor));
      };

    let decodedData = retrievedItem |> parsingFunction |> execute;

    let (transactions, setTransactions) =
      React.useState(_ => decodedData != [||] ? decodedData : [||]);
    ();

    let addTransaction = transaction => {
      // let (transactions, setTransactions) = fetchTransactions();
      let concatenatedString = Array.concat([[|transaction|], transactions]);
  
      setTransactions(_ => concatenatedString); // concat or append
  
      let stringifiedData = Js.Json.stringifyAny(concatenatedString);
  
      switch (stringifiedData) {
      | Some(result) =>
        Dom_storage2.localStorage->Dom_storage2.setItem("transactions", result)
      | None => ()
      };
    };

    (transactions, addTransaction);
  };

  
};
