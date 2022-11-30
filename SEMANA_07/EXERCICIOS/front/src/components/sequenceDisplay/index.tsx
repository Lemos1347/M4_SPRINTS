import { wrap } from "module";
import { useEffect, useState } from "react";
import { ISequence } from "../../interfaces";
import { Sequence } from "./style";

// [1, 2, 3, 4]

export const SequenceDisplay = ({ sequence }: ISequence) => {
  const colors: string[] = ["", "VERDE", "VERMELHO", "AMARELO", "AZUL"];

  return (
    <div
      style={{
        display: "flex",
        width: "100vw",
        justifyContent: "center",
        flexWrap: "wrap",
      }}
    >
      {sequence.map((i) => (
        <Sequence color={i}>{colors[i]}</Sequence>
      ))}
    </div>
  );
};

// switch (i) {
//   case 1:
//     console.log("deu");
//     <Sequence sequence color="green">
//       VERDE{" "}
//     </Sequence>;
//     break;
//   case 2:
//     <Sequence color="red">VERMELHO </Sequence>;
//     break;
//   case 3:
//     <Sequence color="yellow">AMARELO </Sequence>;
//     break;
//   case 4:
//     <Sequence color="blue">AZUL </Sequence>;
//     break;
// }
