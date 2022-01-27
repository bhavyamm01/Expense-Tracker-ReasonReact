[%bs.raw {|require('./App.css')|}];
[@react.component]
let make = () => {
  let (transactions, setTransactions) = React.useState(_ => [||]);

  Js.log2(transactions, "transactions");


  let addTransaction = transaction => {
    let concatenatedArray = Array.concat([[|transaction|], transactions]);

    setTransactions(_ => concatenatedArray); // concat or append
  };

  <div className="container">
    <h2> {React.string("Expense Tracker")} </h2>
    <Amount transactions />
    <History transactions />
    <AddNewTransaction addTransaction />
  </div>;
};
