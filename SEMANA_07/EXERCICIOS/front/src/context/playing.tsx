import React, { createContext, ReactNode, useState } from "react";
import { IPlayingContext } from "../interfaces";

export const PlayingContext = createContext<IPlayingContext>({
  playing: false,
  setPlaying: function (value: React.SetStateAction<boolean>): void {
    throw new Error("Function not implemented.");
  },
});

export const PlayingContextProvider = ({
  children,
}: {
  children: ReactNode;
}) => {
  const [playing, setPlaying] = useState<boolean>(false);

  return (
    <PlayingContext.Provider value={{ playing, setPlaying }}>
      {children}
    </PlayingContext.Provider>
  );
};
