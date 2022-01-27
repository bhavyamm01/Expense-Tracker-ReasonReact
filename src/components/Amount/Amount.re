open Transactions;

[@react.component]
let make = (~transactions: t) => {
  let rupee = React.string({js|₹|js});

  let expenseIncomeStyle =
    ReactDOM.Style.make(
      ~backgroundColor="white",
      ~display="flex",
      ~justifyContent="space-between",
      ~boxShadow="-2px 3px 3px 0px rgba(168, 168, 168, 0.75)",
      ~borderRadius="4px",
      (),
    );
  let incomeStyle = ReactDOM.Style.make(~flex="1", ~textAlign="center", ());
  let incomeH5Style =
    ReactDOM.Style.make(~color="green", ~fontSize="20px", ());
  let expenseStyle = ReactDOM.Style.make(~flex="1", ~textAlign="center", ());
  let expenseH5Style =
    ReactDOM.Style.make(~color="red", ~fontSize="20px", ());

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
    <div style=expenseIncomeStyle>
      <div style=incomeStyle>
        <h3> {React.string("Income")} </h3>
        <h5 style=incomeH5Style> rupee {React.int(income)} </h5>
      </div>
      <div style=expenseStyle>
        <h3> {React.string("Expense")} </h3>
        <h5 style=expenseH5Style> rupee {React.int(expense)} </h5>
      </div>
    </div>
  </div>;
};
