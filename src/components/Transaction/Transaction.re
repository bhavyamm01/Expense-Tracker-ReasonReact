open Types;

[@react.component]
let make = (~transaction: state) => {
  let convert = num => {
    let int_to_string = string_of_int(num);
    let x = int_to_string |> Js.String.split("-");
    let string_to_int = int_of_string(x[1]);

    string_to_int;
  };

  let transactionLiStyle =
    ReactDOM.Style.make(
      ~backgroundColor="white",
      ~padding="2%",
      ~width="100%",
      ~alignItems="center",
      ~justifyContent="space-between",
      ~display="flex",
      ~marginBottom="3%",
      (),
    );

  let greenFinalStyle =
    ReactDOM.Style.make(
      ~width="100%",
      ~boxShadow="-2px 3px 3px 0px rgba(168, 168, 168, 0.75)",
      ~borderRight="4px solid green",
      (),
    );

  let redFinalStyle =
    ReactDOM.Style.make(
      ~width="100%",
      ~boxShadow="-2px 3px 3px 0px rgba(168, 168, 168, 0.75)",
      ~borderRight="4px solid red",
      (),
    );

  transaction.amount > 0
    ? <div style=greenFinalStyle>
        <li style=transactionLiStyle>
          {React.string(transaction.comment)}
          {React.string(" ")}
          <div>
            {transaction.amount > 0
               ? {
                 React.string("+");
               }
               : {
                 React.string("-");
               }}
            {React.string("Rs")}
            {React.string(" ")}
            {transaction.amount < 0
               ? React.int(convert(transaction.amount))
               : React.int(transaction.amount)}
          </div>
        </li>
      </div>
    : <div style=redFinalStyle>
        <li style=transactionLiStyle>
          {React.string(transaction.comment)}
          {React.string(" ")}
          <div>
            {transaction.amount > 0
               ? {
                 React.string("+");
               }
               : {
                 React.string("-");
               }}
            {React.string("Rs")}
            {React.string(" ")}
            {transaction.amount < 0
               ? React.int(convert(transaction.amount))
               : React.int(transaction.amount)}
          </div>
        </li>
      </div>;
};
