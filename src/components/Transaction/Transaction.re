open Transactions;

[@react.component]
let make = (~transaction: state) => {
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

  let signHelper = amount => {
    amount > 0 ? React.string("+") : React.string("-");
  };

  let renderTransaction = () => {
    <li style=transactionLiStyle>
      {React.string(transaction.comment)}
      {React.string(" ")}
      <DisplayAmount transaction=transaction.amount />
    </li>;
  };

  let transactionStyle =
    transaction.amount > 0 ? greenFinalStyle : redFinalStyle;

  <div style=transactionStyle> {renderTransaction()} </div>;
};
