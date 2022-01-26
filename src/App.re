[@react.component]
let make = () => {
  let (transactions, setTransactions) = React.useState(_ => [||]);

  Js.log2(transactions, "transactions");

  let style =
    ReactDOM.Style.make(
      ~maxWidth="500px",
      ~padding="1%",
      ~marginTop="-3%",
      ~marginLeft="auto",
      ~marginRight="auto",
      ~alignItems="center",
      ~justifyContent="center",
      ~background="rgb(227, 227, 227)",
      ~borderRadius="10px",
      ~height="100%",
      ~boxShadow="-2px 3px 2px 0px rgba(168, 168, 168, 0.75)",
      (),
    );

  let addTransaction = transaction => {
    let concatenatedArray = Array.concat([[|transaction|], transactions]);

    setTransactions(_ => concatenatedArray); // concat or append
  };

  <div className="container" style>
    <h2> {React.string("Expense Tracker")} </h2>
    <Amount transactions />
    <History transactions />
    <AddNewTransaction addTransaction />
  </div>;
};
