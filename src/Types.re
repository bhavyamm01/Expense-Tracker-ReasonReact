type state = {
  comment: string,
  amount: int,
};

type action =
  | SetComment(string)
  | SetAmount(int);

type t = array(state);
