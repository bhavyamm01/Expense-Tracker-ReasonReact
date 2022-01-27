[@react.component]
let make = (~transaction: int) => {
  let rupee = React.string({js|₹|js});

  let signHelper = amount =>
    if (amount === 0) {
      React.null;
    } else if (amount > 0) {
      React.string("+");
    } else {
      React.string("-");
    };

  <div>
    {signHelper(transaction)}
    rupee
    {React.int(abs(transaction))}
  </div>;
};
