import { LandingPageContainer, Button, ContainerInformation } from "./style";
import api from "../../utils/axios";
import { useContext, useEffect, useState } from "react";
import { Title } from "../title";
import { PlayingContext } from "../../context/playing";

const LandingPage = () => {
  const [displayRules, setDisplayRules] = useState<boolean>(false);
  const [wantToplay, setWantToplay] = useState<boolean>(false);

  const { playing, setPlaying } = useContext(PlayingContext);

  const handleClick = async () => {
    await api
      .get("/")
      .then(async () => {
        await setPlaying(true);
      })
      .catch((err) => {
        console.log(err);
      });
  };

  return (
    <LandingPageContainer>
      <Title value="BEM VINDO AO GENIUS V2" />
      <Button onClick={handleClick}>COMEÇAR</Button>
      <Button
        onClick={() => {
          displayRules ? setDisplayRules(false) : setDisplayRules(true);
        }}
      >
        REGRAS
      </Button>
      {displayRules && (
        <ContainerInformation>
          Esse jogo é a recriação do clássico jogo "Genius". Ele foi criado para
          ser jogado em duas pessoas. Assim que apertarem o botão de começar, um
          buzzer tocará na plaquinha avisando o começo. Assim que acabar o
          buzzer, a primeira sequência tocará. Cada jogador é responsável por
          marcar na tela a respectiva sequência demonstrada no ESP32. Caso, o
          jogador erre a sequência, o outro jogador será o vencedor. Boa sorte!{" "}
        </ContainerInformation>
      )}
    </LandingPageContainer>
  );
};

export default LandingPage;
