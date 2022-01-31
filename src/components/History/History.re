[%bs.raw {|require('./History.css')|}];

[@react.component]
let make = (~transactions: array(Transaction.t)) => {
  <div className="history">
    <h3> {React.string("History")} </h3>
    <hr />
    <ul className="history-ul">
      {transactions
       ->Belt.Array.map(transaction => <TransactionCmp transaction />)
       ->React.array}
    </ul>
  </div>;
};
