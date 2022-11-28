import { builtinModules } from "module";
import styled from "styled-components";

export const MainContainer = styled.div`
  width: 100%;
  height: 100%;
  display: flex;
`;

export const ButtonColor = styled.button.attrs((props) => {})`
  margin: 0 auto auto auto;
  border: none;
  border-radius: 1rem;
  background-color: ${(props) => props.background};
  color: white;
  font-size: 2rem;
  padding: 1rem;
  &:hover {
    background-color: ${(props) => props.color};
  }
`;

export const ButtonSend = styled.button.attrs((props) => {})`
  display: block;
  margin: 10rem auto 0 auto;
  border: none;
  border-radius: 1rem;
  background-color: ${(props) => props.background};
  color: white;
  font-size: 2rem;
  padding: 1rem;
  &:hover {
    background-color: ${(props) => props.color};
  }
`;

export const FimDeJogo = styled.div`
  margin: 0 0 10% 0;
  font-size: 3rem;
  text-align: center;
  justify-content: center;
`;
