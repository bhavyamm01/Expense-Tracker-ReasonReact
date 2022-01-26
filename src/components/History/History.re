[@react.component]
let make = (~transactions: Transactions.t) => {
  let historyUlStyle =
    ReactDOM.Style.make(
      ~listStyle="none",
      ~alignItems="center",
      ~justifyContent="center",
      ~maxHeight="110px",
      ~overflowY="auto",
      (),
    );

  <div className="history" id="history">
    <h3> {React.string("History")} </h3>
    <hr />
    <ul style=historyUlStyle>
      {transactions
       ->Belt.Array.map(transaction => <Transaction transaction />)
       ->React.array}
    </ul>
  </div>;
};
