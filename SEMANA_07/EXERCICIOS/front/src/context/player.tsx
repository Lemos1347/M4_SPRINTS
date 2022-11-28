import React, { createContext, ReactNode, useState } from "react";
import { IPlayerContext } from "../interfaces";

export const PlayerContext = createContext<IPlayerContext>({
  playerOne: true,
  playerTwo: true,
  setPlayerOne: function (value: React.SetStateAction<boolean>): void {
    throw new Error("Function not implemented.");
  },
  setPlayerTwo: function (value: React.SetStateAction<boolean>): void {
    throw new Error("Function not implemented.");
  },
});

export const PlayerContextProvider = ({
  children,
}: {
  children: ReactNode;
}) => {
  const [playerOne, setPlayerOne] = useState<boolean>(true);
  const [playerTwo, setPlayerTwo] = useState<boolean>(false);

  return (
    <PlayerContext.Provider
      value={{ playerOne, playerTwo, setPlayerOne, setPlayerTwo }}
    >
      {children}
    </PlayerContext.Provider>
  );
};
