open Transactions;
[%bs.raw {|require('./Amount.css')|}];

[@react.component]
let make = (~transactions: array(t)) => {
  let rupee = React.string({js|₹|js});

  let amountArray = Belt.Array.map(transactions, t => t.amount);
  let incomeArray = Belt.Array.keep(amountArray, i => i > 0);
  let expenseArray = Belt.Array.keep(amountArray, i => i < 0);

  let calculateTotal = requiredArray => {
    Belt.Array.reduce(requiredArray, 0, (acc, value) => acc + value);
  };

  let total = calculateTotal(amountArray);
  let income = calculateTotal(incomeArray);
  let expense = calculateTotal(expenseArray);
  ();

  <div>
    <div className="balance">
      <h3> {React.string("Your balance")} </h3>
      <h1> <DisplayAmount transaction=total /> </h1>
    </div>
    <div className="expense-income-div">
      <div className="income-div">
        <h3> {React.string("Income")} </h3>
        <h5 className="income-h5"> rupee {React.int(income)} </h5>
      </div>
      <div className="income-div">
        <h3> {React.string("Expense")} </h3>
        <h5 className="expense-h5"> rupee {React.int(expense)} </h5>
      </div>
    </div>
  </div>;
};
