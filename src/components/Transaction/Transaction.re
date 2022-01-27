open Transactions;

[%bs.raw {|require('./Transaction.css')|}];

[@react.component]
let make = (~transaction: t) => {
  let renderTransaction = () => {
    <li className="transaction-li">
      {React.string(transaction.comment ++ " ")}
      <DisplayAmount transaction={transaction.amount} />
    </li>;
  };

  <div className={transaction.amount > 0 ? "green" : "red"}>
    {renderTransaction()}
  </div>;
};
