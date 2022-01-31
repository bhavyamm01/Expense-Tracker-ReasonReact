[%bs.raw {|require('./TransactionCmp.css')|}];

[@react.component]
let make = (~transaction: Transaction.t) => {
  let renderTransaction = () => {
    <li className="transaction-li">
      {React.string(transaction.comment ++ " ")}
      <DisplayAmount amount={transaction.amount} />
    </li>;
  };

  <div className={transaction.amount > 0 ? "green" : "red"}>
    {renderTransaction()}
  </div>;
};
