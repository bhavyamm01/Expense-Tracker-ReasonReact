[%bs.raw {|require('./History.css')|}];

[@react.component]
let make = (~transactions: array(Transactions.t)) => {
  <div className="history" id="history">
    <h3> {React.string("History")} </h3>
    <hr />
    <ul className="history-ul">
      {transactions
       ->Belt.Array.map(transaction => <Transaction transaction />)
       ->React.array}
    </ul>
  </div>;
};
