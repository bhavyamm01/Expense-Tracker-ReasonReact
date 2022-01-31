[%bs.raw {|require('./App.css')|}];

open TransactionsStore;

[@react.component]
let make = () => {
  let (transactions, addTransaction) = TransactionsStore.fetchTransactions();

  <div className="container">
    <h2> {React.string("Expense Tracker")} </h2>
    <Amount transactions />
    <History transactions />
    <AddNewTransaction addTransaction />
  </div>;
};
