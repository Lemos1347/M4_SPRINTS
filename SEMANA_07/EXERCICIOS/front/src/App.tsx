import React, { useContext, useState } from "react";
import { useEffect } from "react";
import LandingPage from "./components/landingPage";
import PlayingPage from "./components/playingPage";
import { PlayerContext, PlayerContextProvider } from "./context/player";
import { PlayingContextProvider, PlayingContext } from "./context/playing";

function App() {
  return (
    <PlayingContextProvider>
      <PlayerContextProvider>
        <Child />
      </PlayerContextProvider>
    </PlayingContextProvider>
  );
}

const Child = () => {
  const { playing } = useContext(PlayingContext);
  const { setPlayerOne, setPlayerTwo } = useContext(PlayerContext);

  useEffect(() => {
    setPlayerOne(true);
    setPlayerTwo(false);
  }, [playing]);

  return <>{!playing ? <LandingPage /> : <PlayingPage />}</>;
};

export default App;
