type transaction = {
  comment: string,
  amount: int,
};

type t = array(transaction);

let (transactions: t, setTransactions) = React.useState(() => [||]);

let globalContext = React.createContext(transactions);

let make = React.Context.provider(globalContext);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};
