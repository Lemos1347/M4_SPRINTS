import styled from "styled-components";

const colors: string[] = ["", "green", "red", "yellow", "blue"];

export const Sequence = styled.div.attrs((props) => {})`
  flex-wrap: wrap;
  margin: 2rem 2rem auto 2rem;
  color: ${(props: { color: number }) => colors[props.color]};
  font-size: 2rem;
`;
